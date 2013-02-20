#include <iostream>
#include <stdio.h>
#include "mongoose.h"
using namespace std;

#if !defined(CONFIG_FILE)
#define	CONFIG_FILE		"mongoose.conf"
#endif /* !CONFIG_FILE */
static int exit_flag;	
#include <signal.h>

#ifdef _WIN32
#include <windows.h>
#include <winsvc.h>
#include <winbase.h>
#define DIRSEP			'\\'
#define	snprintf		_snprintf
#if !defined(__LCC__)
#define	strdup(x)		_strdup(x)
#endif /* !MINGW */
#define	sleep(x)		Sleep((x) * 1000)
#else
#include <sys/wait.h>
#include <unistd.h>		/* For pause() */
#define DIRSEP '/'
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

/* Default cycle time value 5 minutes */
#define CYCLE		(5*60)
#endif /* _WIN32 */

struct mg_context	*ctx;

//// Global /////////////////////////////////////////////////////////
#ifdef _WIN32
FILE*		pLog;							
char*		ServiceName = "DashWebServer";		// Name of the service
HANDLE		terminateEvent = NULL;			// Event used to hold ServerMain from completing
											// Handle used to communicate status info with 
											// the SCM. Created by RegisterServiceCtrlHandler
HANDLE		threadHandle = 0;				// Thread for the actual work
BOOL		pauseService = FALSE;			// Flags holding current state of service
BOOL		runningService = FALSE;			//
SERVICE_STATUS_HANDLE serviceStatusHandle;	//

DWORD	WINAPI ServiceThread( LPDWORD lParam);
BOOL	InitService();
BOOL	SendStatusToSCM(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwServiceSpecificExitCode, DWORD dwCheckPoint, DWORD dwWaitHint);
void	ResumeService();
void	PauseService();
void	StopService();
void	terminate(DWORD error);
void	ServiceCtrlHandler(DWORD controlCode);
void	ServiceMain(DWORD argc, LPTSTR *argv);
void	GetStatus(SC_HANDLE service);
void	ShowUsage();
// service config program tasks
bool	InstallService();
bool	UninstallService();
bool	GetConfiguration();
bool	ChangeConfig();
// service control program tasks
bool	ServiceRun();
bool	ServiceControl(char* CONTROL);
#else
int ServerStart();
#endif

static void
signal_handler(int sig_num)
{
#if !defined(_WIN32)
	if (sig_num == SIGCHLD) {
		do {
		} while (waitpid(-1, &sig_num, WNOHANG) > 0);
	} else
#endif /* !_WIN32 */
	{
		exit_flag = sig_num;
	}
}

static void
show_usage_and_exit(void)
{
	mg_show_usage_string(stderr);
	exit(EXIT_FAILURE);
}

static void
process_command_line_arguments(struct mg_context *ctx, char *argv[])
{
	const char	*config_file = CONFIG_FILE;
	char		line[512], opt[512], *vals[100],
				val[512], path[FILENAME_MAX], *p;
	FILE		*fp;
	size_t		i, line_no = 0;

	char *envpath = getenv("MONGOOSE_CONF");
	if(envpath != NULL)
	{
		config_file = envpath;
		
	}
	else
		return;
	

	fp = fopen(config_file, "r");

	/* Reset temporary value holders */
	(void) memset(vals, 0, sizeof(vals));

	if (fp != NULL) {
		(void) printf("Loading config file %s\n", config_file);

		/* Loop over the lines in config file */
		while (fgets(line, sizeof(line), fp) != NULL) {

			line_no++;

			/* Ignore empty lines and comments */
			if (line[0] == '#' || line[0] == '\n')
				continue;

			if (sscanf(line, "%s %[^\r\n#]", opt, val) != 2) {
				fprintf(stderr, "%s: line %d is invalid\n",
				    config_file, (int) line_no);				
				exit(EXIT_FAILURE);
			}
			if (mg_set_option(ctx, opt, val) != 1)
				exit(EXIT_FAILURE);
		}

		(void) fclose(fp);
	}

	/* Now pass through the command line options */
	/*for (i = 1; argv[i] != NULL && argv[i][0] == '-'; i += 2)
		if (mg_set_option(ctx, &argv[i][1], argv[i + 1]) != 1)
			exit(EXIT_FAILURE);*/
}
static void
show_index(struct mg_connection *conn, const struct mg_request_info *request_info,
		void *user_data)
{
	mg_printf(conn, "%s",
		"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
		"<html><body><h1>Welcome to DASH Integrated Mongoose Web Server  </h1></body></html>");		
}



int main(int argc, char *argv[])
{

#ifndef _WIN32
	
	argc = argc;
	argv = argv;

	int cycle_time;	

	/* Inits */
	cycle_time = CYCLE;
	
	if( signal( SIGINT, SIG_IGN ) != SIG_IGN )
		signal( SIGINT, SIG_IGN );
	if( signal( SIGKILL, SIG_IGN ) != SIG_IGN )
		signal( SIGKILL, SIG_IGN );
	

	if( fork() == 0 )    {
		fclose( stdin );
		fclose( stdout );		

		/* Forever */
		while( 1 )    {
			ServerStart();			 
			/* Wake up and look every cycle_time */
			sleep( cycle_time );			
		}
	}
	else    {
		/* Exit parent process */
		if( signal( SIGINT, SIG_DFL ) != SIG_DFL )
			signal( SIGINT, SIG_DFL );
		if( signal( SIGKILL, SIG_DFL ) != SIG_DFL )
			signal( SIGKILL, SIG_DFL );
		exit( 0 );

	} /* End if( fork() ) */	

	exit( 0 );
#else
	SERVICE_TABLE_ENTRY serviceTable[] =
	{
		{ ServiceName, (LPSERVICE_MAIN_FUNCTION) ServiceMain},
		{ NULL, NULL}
	};
	//BOOL success;
	
	if(argc == 2)
	{
		if (stricmp("-i", argv[1]) == 0)
			InstallService();
		else if (stricmp("-u", argv[1]) == 0)			
			UninstallService();
		else if (stricmp("-r", argv[1]) == 0)
			ServiceRun();
		else if (stricmp("-s", argv[1]) == 0)
			ServiceControl("STOP");		
	}
	else 
	{
		//register with SCM
		StartServiceCtrlDispatcher(serviceTable);		
	}
#endif
	return 0;
}
#ifndef _WIN32
int ServerStart()
{
	
	(void) signal(SIGCHLD, signal_handler);	
	(void) signal(SIGTERM, signal_handler);
	(void) signal(SIGINT, signal_handler);

	if ((ctx = mg_start()) == NULL) {
		(void) printf("%s\n", "Cannot initialize Mongoose context");
		exit(EXIT_FAILURE);
		}

	char *argv[] = {"0"};
	process_command_line_arguments(ctx, argv);
	
	if (mg_get_option(ctx, "ports") == NULL &&
		mg_set_option(ctx, "ports", "8080") != 1)
		exit(EXIT_FAILURE);
	mg_set_option(ctx, "root", "/");	
	mg_set_uri_callback(ctx, "/", &show_index, (void *) NULL);
	return(0);
}
#else
void ServiceMain(DWORD argc, LPTSTR *argv)
{
	BOOL success;

	//immediately call registration function 
	serviceStatusHandle = RegisterServiceCtrlHandler(ServiceName, (LPHANDLER_FUNCTION)ServiceCtrlHandler);
	if (!serviceStatusHandle)
	{
		terminate(GetLastError());
		return;
	}

	//notify SCM
	success = SendStatusToSCM(SERVICE_START_PENDING, NO_ERROR, 0 , 1, 5000);
	if (!success)
	{ 
		terminate(GetLastError());
		return;
	}

	//create termination event
	terminateEvent = CreateEvent (0, TRUE, FALSE, 0);
	if (!terminateEvent)
	{
		terminate(GetLastError());
		return;
	}

	//notify SCM
	success = SendStatusToSCM(SERVICE_START_PENDING, NO_ERROR, 0 , 2, 1000);
	if (!success)
	{ 
		terminate(GetLastError());
		return;
	}

	//notify SCM
	success = SendStatusToSCM(SERVICE_START_PENDING, NO_ERROR, 0 , 3, 5000);
	if (!success)
	{ 
		terminate(GetLastError());
		return;
	}

	//start service
	success = InitService();
	if (!success)
	{ 
		terminate(GetLastError());
		return;
	}

	//notify SCM service is runnning
	success = SendStatusToSCM(SERVICE_RUNNING, NO_ERROR, 0 , 0, 0);
	if (!success)
	{ 
		terminate(GetLastError());
		return;
	}

	//wait for stop signal and then terminate
	WaitForSingleObject(terminateEvent, INFINITE);

	terminate(0);
}


DWORD WINAPI ServiceThread(LPDWORD lParam)
{
	
	#ifndef _WIN32
	(void) signal(SIGCHLD, signal_handler);
	#endif /* _WIN32 */
	(void) signal(SIGTERM, signal_handler);
	(void) signal(SIGINT, signal_handler);

	if ((ctx = mg_start()) == NULL) {
		(void) printf("%s\n", "Cannot initialize Mongoose context");
		exit(EXIT_FAILURE);
	}

	char *argv[] = {"0"};
	process_command_line_arguments(ctx, argv);
		if (mg_get_option(ctx, "ports") == NULL &&
			mg_set_option(ctx, "ports", "8080") != 1)
			exit(EXIT_FAILURE);

	char szBuffer[1024];
	::GetLogicalDriveStrings(1024, szBuffer);	
	std::string aliases;
	char *pch = szBuffer;
	while (*pch) {    
		aliases.append("/");
		aliases.append(pch);
		aliases.erase(aliases.length()-1);
		aliases.append("=");
		aliases.append(pch);
		aliases.append(",");
		pch = &pch[strlen(pch) + 1];
	}
	aliases.erase(aliases.length()-1);
	mg_set_option(ctx, "aliases", aliases.c_str());

	mg_set_uri_callback(ctx, "/", &show_index, (void *) NULL);

	return 0;
}

//initialises the service by starting its thread
BOOL InitService()
{
	DWORD id;

	// Start the service's thread
	threadHandle = CreateThread(
	NULL,
	0,
	(LPTHREAD_START_ROUTINE) ServiceThread,
	NULL,
	0,
	&id);
	
	if (threadHandle == 0)
		return FALSE;
	else
	{
		runningService = TRUE;
		return TRUE;
	}
}

//resumes paused service
void ResumeService()
{
	pauseService = FALSE;
	ResumeThread(threadHandle);
}

//pauses service
void PauseService()
{
	pauseService = TRUE;
	SuspendThread(threadHandle);
}

//stops service by allowing ServiceMain to complete
void StopService()
{
	runningService = FALSE;
	//set the event that is holding ServiceMain
	SetEvent(terminateEvent);
}

//this function consolidates the activities of updating
//the service status with SetServiceStatus
BOOL SendStatusToSCM(DWORD dwCurrentState, DWORD dwWin32ExitCode, DWORD dwServiceSpecificExitCode, DWORD dwCheckPoint, DWORD dwWaitHint)
{
	BOOL success;
	SERVICE_STATUS serviceStatus;

	//fill in all of the SERVICE_STATUS fields
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState = dwCurrentState;

	//if in the process of something, then accept
	//no control events, else accept anything
	if (dwCurrentState == SERVICE_START_PENDING)
		serviceStatus.dwControlsAccepted = 0;
	else
		serviceStatus.dwControlsAccepted = 
			SERVICE_ACCEPT_STOP | 
			SERVICE_ACCEPT_PAUSE_CONTINUE |
			SERVICE_ACCEPT_SHUTDOWN;

	//if a specific exit code is defines, set up the win32 exit code properly
	if (dwServiceSpecificExitCode == 0)
		serviceStatus.dwWin32ExitCode = dwWin32ExitCode;
	else
		serviceStatus.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
	
	serviceStatus.dwServiceSpecificExitCode = dwServiceSpecificExitCode;
	serviceStatus.dwCheckPoint = dwCheckPoint;
	serviceStatus.dwWaitHint = dwWaitHint;
	
	success = SetServiceStatus (serviceStatusHandle, &serviceStatus);
	if (!success)
		StopService();

	return success;
}

void ServiceCtrlHandler(DWORD controlCode)
{
	DWORD currentState = 0;
	BOOL success;

	switch(controlCode)
	{
		// START = ServiceMain()

		// STOP
		case SERVICE_CONTROL_STOP:
			currentState = SERVICE_STOP_PENDING;
			//notify SCM
			success = SendStatusToSCM(
				SERVICE_STOP_PENDING,
				NO_ERROR,
				0,
				1,
				5000);
			//stop service
			StopService();
			return;

		// PAUSE
		case SERVICE_CONTROL_PAUSE:
			if (runningService && !pauseService)
			{
				//notify SCM
				success = SendStatusToSCM(
					SERVICE_PAUSE_PENDING,
					NO_ERROR,
					0,
					1,
					1000);
				
				PauseService();
				currentState = SERVICE_PAUSED;
			}
			break;
			
		// RESUME
		case SERVICE_CONTROL_CONTINUE:
			if (runningService && pauseService)
			{
				//notify SCM
				success = SendStatusToSCM(
					SERVICE_CONTINUE_PENDING,
					NO_ERROR,
					0,
					1,
					1000);
				
				ResumeService();
				currentState = SERVICE_RUNNING;
			}
			break;

		// UPDATE
		case SERVICE_CONTROL_INTERROGATE:
			//update status out of switch()
			break;
			
		case SERVICE_CONTROL_SHUTDOWN:
			//do nothing
			return;
		default:
			break;
	}
	//notify SCM current state
	SendStatusToSCM(currentState, NO_ERROR, 0, 0, 0);
}
	

//handle an error from ServiceMain by cleaning up and tell SCM service didn't start.
void terminate(DWORD error)
{
	//close event handle
	if (terminateEvent)
		CloseHandle(terminateEvent);

	//notify SCM service stopped
	if (serviceStatusHandle)
		SendStatusToSCM(SERVICE_STOPPED, error, 0, 0, 0);

	//close thread handle
	if (threadHandle)
		CloseHandle(threadHandle);
}

////////////////////////////////////////////////////////////////////////////////
// Purpose	:Install service into SCM.
// Parameter:N/A
// Returns	:N/A
////////////////////////////////////////////////////////////////////////////////
bool InstallService()
{
	SC_HANDLE newService;
	SC_HANDLE scm; 
    char szBuffer[255];
    char szPath[MAX_PATH];

	//get file path
	GetModuleFileName( GetModuleHandle(NULL), szPath, MAX_PATH );
    strcpy( szBuffer, "\"" );
    strcat( szBuffer, szPath );
    strcat( szBuffer, "\"" );

	//open connection to SCM
	scm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
	if (!scm)
		return false;

	//install service
	newService = CreateService(
		scm,						//scm database
		ServiceName,				//service name
		ServiceName,				//display name
		SERVICE_ALL_ACCESS,			//access rights to the service
		SERVICE_WIN32_OWN_PROCESS,	//service type
		SERVICE_AUTO_START,			//service start type
		SERVICE_ERROR_NORMAL,		//error control type
		szBuffer,					//service path
		NULL,						//no load ordering group 
		NULL,						//no tag identifier
		NULL,						//no dependencies	
		NULL,						//LocalSystem account
		NULL);						//no password
	if(!newService)
		return false;
	else
	{
		//cout << "Service Installed" << endl;
		ServiceRun();
	}

	//clean up
	CloseServiceHandle(newService);
	CloseServiceHandle(scm);
	
	return true;

}

////////////////////////////////////////////////////////////////////////////////
// Purpose	:Uninstall service from SCM.
// Parameter:N/A
// Returns	:N/A
////////////////////////////////////////////////////////////////////////////////
bool UninstallService()
{
	SC_HANDLE service;
	SC_HANDLE scm;
	BOOL SUCCESS;
	SERVICE_STATUS status;

	//Open connection to SCM
	scm = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
	if (!scm)
		return false;

	//Get service's handle
	service = OpenService(scm, ServiceName, SERVICE_ALL_ACCESS | DELETE);
	if (!service)
		return false;

	//Get service status
	SUCCESS	= QueryServiceStatus(service, &status);
	if (!SUCCESS)
		return false;
	
	//Stop service if necessary		
	if (status.dwCurrentState != SERVICE_STOPPED)
	{
		//cout << "Stopping service..." << endl;
		SUCCESS = ControlService(service, SERVICE_CONTROL_STOP, &status);
		if (!SUCCESS)
			return false;
		Sleep(500);
	}

	//Delete service
	SUCCESS = DeleteService(service);
	if (!SUCCESS)		
		return false;

	//Clean up
	CloseServiceHandle(service);
	CloseServiceHandle(scm);

	return true;
}


////////////////////////////////////////////////////////////////////////////////
// Purpose	:Run service
// Parameter:N/A
// Returns	:N/A
////////////////////////////////////////////////////////////////////////////////
bool ServiceRun() 
{ 
    SC_HANDLE scm, Service;
	SERVICE_STATUS ssStatus; 
    DWORD dwOldCheckPoint; 
    DWORD dwStartTickCount;
    DWORD dwWaitTime;
    DWORD dwStatus;
 	
	//open connection to SCM
	scm = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!scm)
		return false;

	//open service
	Service = OpenService(scm, ServiceName, SERVICE_ALL_ACCESS);
	if(!Service)
		return false;
	else
	{
		//start service
		StartService(Service, 0, NULL);
		GetStatus(Service);

		// Check the status until the service is no longer start pending. 
		if (!QueryServiceStatus( Service, &ssStatus) )
			return false;
		// Save the tick count and initial checkpoint.
		dwStartTickCount = GetTickCount();
		dwOldCheckPoint = ssStatus.dwCheckPoint;

		while (ssStatus.dwCurrentState == SERVICE_START_PENDING) 
		{ 
			// Do not wait longer than the wait hint. A good interval is 
			// one tenth the wait hint, but no less than 1 second and no 
			// more than 10 seconds. 
			dwWaitTime = ssStatus.dwWaitHint / 10;

			if( dwWaitTime < 1000 )
				dwWaitTime = 1000;
			else if ( dwWaitTime > 10000 )
				dwWaitTime = 10000;

			Sleep( dwWaitTime );

			// Check the status again. 
			if (!QueryServiceStatus(Service, &ssStatus) )
				break; 

			if ( ssStatus.dwCheckPoint > dwOldCheckPoint )
			{
				// The service is making progress.
				dwStartTickCount = GetTickCount();
				dwOldCheckPoint = ssStatus.dwCheckPoint;
			}
			else
			{
				if(GetTickCount()-dwStartTickCount > ssStatus.dwWaitHint)
				{
					// No progress made within the wait hint
					break;
				}
			}
		}
		
		if (ssStatus.dwCurrentState == SERVICE_RUNNING) 
		{
			GetStatus(Service);
			dwStatus = NO_ERROR;
		}
		else 
		{ 

			cout << "\nService not started." << endl;
			cout << "  Current State: " << ssStatus.dwCurrentState << endl; 
			cout << "  Exit Code: " << ssStatus.dwWin32ExitCode << endl; 
			cout << "  Service Specific Exit Code: " << ssStatus.dwServiceSpecificExitCode << endl; 
			cout << "  Check Point: " << ssStatus.dwCheckPoint << endl; 
			cout << "  Wait Hint: " << ssStatus.dwWaitHint << endl;
			dwStatus = GetLastError();
		} 	
	}

	CloseServiceHandle(scm);
    CloseServiceHandle(Service); 
    return true;
}


////////////////////////////////////////////////////////////////////////////////
// Purpose	:Control service (STOP, PAUSE, CONTINUE).
// Parameter:N/A
// Returns	:N/A
////////////////////////////////////////////////////////////////////////////////
bool ServiceControl(char* CONTROL)
{
	SC_HANDLE service;
	SC_HANDLE scm;
	BOOL SUCCESS;
	SERVICE_STATUS status;

	SERVICE_STATUS_PROCESS ssp;
    DWORD dwStartTime = GetTickCount();
    DWORD dwBytesNeeded;
    DWORD dwTimeout = 30000;

	//Open connection to SCM
	scm = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!scm)
		return false;

	//Get service's handle
	service = OpenService(scm, ServiceName, SERVICE_ALL_ACCESS);
	if (!service)
		return false;
	
	//stop the service
	if (stricmp(CONTROL, "STOP") == 0)
	{
		//cout << "Service is stopping..." << endl;		
		 if ( !QueryServiceStatusEx( 
            service, 
            SC_STATUS_PROCESS_INFO,
            (LPBYTE)&ssp, 
            sizeof(SERVICE_STATUS_PROCESS),
            &dwBytesNeeded ) )
		{
			printf("QueryServiceStatusEx failed (%d)\n", GetLastError()); 
			goto stop_cleanup;
		}
		 if ( ssp.dwCurrentState == SERVICE_STOPPED )
			 return true;

		 SUCCESS = ControlService(service, SERVICE_CONTROL_STOP, &status);
		 if (!SUCCESS)
			   goto stop_cleanup;

		 while ( ssp.dwCurrentState != SERVICE_STOPPED ) 
		{
			Sleep( ssp.dwWaitHint );
			if ( !QueryServiceStatusEx( 
					service, 
					SC_STATUS_PROCESS_INFO,
					(LPBYTE)&ssp, 
					sizeof(SERVICE_STATUS_PROCESS),
					&dwBytesNeeded ) )
			{
				printf( "QueryServiceStatusEx failed (%d)\n", GetLastError() );
				goto stop_cleanup;
			}
			if ( ssp.dwCurrentState == SERVICE_STOPPED )
				return true;

			if ( GetTickCount() - dwStartTime > dwTimeout )
				goto stop_cleanup;
		}

	}
	//pause the service
	else if (stricmp(CONTROL, "PAUSE") == 0)
	{
		//cout << "Service is pausing..." << endl;
		SUCCESS = ControlService(service, SERVICE_CONTROL_PAUSE, &status);
		goto stop_cleanup;
	}
	//continue the service
	else if (stricmp(CONTROL, "RESUME") == 0)
	{
		//cout << "Service is resuming..." << endl;
		SUCCESS = ControlService(service, SERVICE_CONTROL_CONTINUE, &status);
		goto stop_cleanup;
	}
	if (!SUCCESS)
		return false;
	else
		GetStatus(service);

	//Clean up
stop_cleanup:
	CloseServiceHandle(service);
	CloseServiceHandle(scm);

	return true;
}


////////////////////////////////////////////////////////////////////////////////
// Purpose	:Get the current status of the service
// Parameter:service handle.
// Returns	:N/A
////////////////////////////////////////////////////////////////////////////////
void GetStatus(SC_HANDLE service)
{
	BOOL SUCCESS;
	SERVICE_STATUS status;	
	DWORD CurrentState;

	SUCCESS = QueryServiceStatus(service, &status);
	
	switch(status.dwCurrentState)
	{
		case SERVICE_RUNNING:
			CurrentState = SERVICE_RUNNING;
			//cout << "Service RUNNING." << endl;
			break;
		case SERVICE_STOPPED:
			CurrentState = SERVICE_STOPPED;
			//cout << "Service STOPPED." << endl;
			break;
		case SERVICE_PAUSED:
			CurrentState = SERVICE_PAUSED;
			//cout << "Service PAUSED." << endl;
			break;
		case SERVICE_CONTINUE_PENDING:
			CurrentState = SERVICE_CONTINUE_PENDING;
			//cout << "Service is resuming..." << endl;
			break;
		case SERVICE_PAUSE_PENDING:
			CurrentState = SERVICE_PAUSE_PENDING;
			//cout << "Service is pausing..." << endl;
			break;
		case SERVICE_START_PENDING:
			CurrentState = SERVICE_START_PENDING;
			//cout << "Service is starting..." << endl;
			break;
		case SERVICE_STOP_PENDING:
			CurrentState = SERVICE_STOP_PENDING;
			//cout << "Service is stopping..." << endl;
			break;
		default:
			break;
	}
	SendStatusToSCM(CurrentState, NO_ERROR, 0, 0, 0);
}
#endif