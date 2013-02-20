#ifndef __DSDK_CIMCAPABILITIES_H__
#define __DSDK_CIMCAPABILITIES_H__

#include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/oal/CIM_ManagedElement.h>
#include <dsdk/oal/CIM_EnabledLogicalElementCapabilities.h>
#include <dsdk/oal/CIM_USBRedirectionCapabilities.h>
#include <dsdk/oal/CIM_Dependency.h>
#include <cmci/cmci.h>
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>
#include <dsdk/cim/cimutils.h>


#include <vector>

using std::vector;

namespace dsdk
{
class CCIMCapabilities
{
public:
	CCIMCapabilities(void);
	~CCIMCapabilities(void);

	static vector<uint16> getSupportedStates(IClient* client, const CIM_ManagedElement me);
						//CIM_EnabledLogicalElementCapabilities capabilities);

	static vector<string> getSupportedStatesStr(IClient* client, const CIM_ManagedElement me);

	static bool isSupportedValue(IClient*  client, 
													CIM_ManagedElement me, 
													uint16 checkVal);

	static CIM_EnabledLogicalElementCapabilities getCapabilityInstance(
	IClient*  client, CIM_ManagedElement me);

	//static bool CCIMCapabilities::isCapabilitySetTo(
	//	IClient*  client, CIM_ManagedElement me, uint16 propVal);

	//static bool CCIMCapabilities::isCapabilitySetTo(
	//	IClient*  client, CIM_ManagedElement me, string propVal);
};
};
#endif /*cimcapabilities_H_*/