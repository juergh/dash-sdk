#include <dsdk/cimcapabilities.h>

using namespace dsdk;

CCIMCapabilities::CCIMCapabilities(void)
{
}

CCIMCapabilities::~CCIMCapabilities(void)
{
}


vector<uint16> CCIMCapabilities::getSupportedStates(IClient*  client, CIM_ManagedElement me) 
{
	vector<string> props;
	props.push_back("RequestedStatesSupported");
	vector<uint16> caps;

	CIM_EnabledLogicalElementCapabilities::iterator eleciter = 
		CIM_ElementCapabilities<CIM_ManagedElement, CIM_EnabledLogicalElementCapabilities>::
		enumerateCapabilities(client,me, props);

	if (eleciter == CIM_EnabledLogicalElementCapabilities::iterator::end ())	{
		return caps;
	} 
	
	CIM_EnabledLogicalElementCapabilities elcaps = *eleciter;

	// Note: Following func call throughs CIM_Error is there is no RequestedStatesSupported Property exists for ME
	// Need to find better ways to handle error.
		caps = elcaps.getRequestedStatesSupported(); 
	return caps;
}

vector<string> CCIMCapabilities::getSupportedStatesStr(IClient*  client, CIM_ManagedElement me) 
{
	vector<string> empty_props;
	vector<string> strstates;
	vector<uint16> valstates;

	CIM_EnabledLogicalElementCapabilities::iterator eleciter = 
		CIM_ElementCapabilities<CIM_ManagedElement, CIM_EnabledLogicalElementCapabilities>::
		enumerateCapabilities(client,me, empty_props);

	if (eleciter == CIM_EnabledLogicalElementCapabilities::iterator::end ())	{
		fprintf (stdout, "Unable to retrieve the associated capabilities  Instance");
	} 
	
	CIM_EnabledLogicalElementCapabilities elcaps = *eleciter;
	valstates = elcaps.getRequestedStatesSupported();
	for (size_t i=0; i < valstates.size(); i++)
	{
		strstates.push_back( elcaps.getValueStr_RequestedStatesSupported(valstates[i]));
	}
	return strstates;
}

bool CCIMCapabilities::isSupportedValue(IClient*  client, CIM_ManagedElement me,uint16 checkVal) 
{
  
	vector<uint16> caps = getSupportedStates(client, me);

	for(size_t i=0;i<caps.size();i++) {
		if(checkVal == caps.at(i)) return true;
	}
	return false;
}


CIM_EnabledLogicalElementCapabilities CCIMCapabilities::getCapabilityInstance(
	IClient*  client, CIM_ManagedElement me) {

	vector<string> empty_props;
	CIM_EnabledLogicalElementCapabilities capInst(CCIMInstance::nullInstance ());

	CIM_EnabledLogicalElementCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_ManagedElement, CIM_EnabledLogicalElementCapabilities>::
			enumerateCapabilities (client, me, empty_props);

	if (eleciter == CIM_EnabledLogicalElementCapabilities::iterator::end ()) {
		return capInst;
	} 
	capInst = *eleciter;
	return capInst;
}