REM
REM <AMD 3BSD notice header>
REM
REM Copyright (c) 2006, 2007, 2008 Advanced Micro Devices, Inc.
REM
REM All rights reserved.
REM
REM This file is subject to the license found in the LICENSE.AMD file which
REM states the following in part:
REM
REM Redistribution and use in any form of this material and any product
REM thereof including software in source or binary forms, along with any
REM related documentation, with or without modification ("this material"),
REM is permitted provided that the following conditions are met:
REM
REM   * Redistributions of source code of any software must retain the above
REM     copyright notice and all terms of this license as part of the code.
REM
REM   * Redistributions in binary form of any software must reproduce the
REM     above copyright notice and all terms of this license in any related
REM     documentation and/or other materials. 
REM
REM   * Neither the names nor trademarks of Advanced Micro Devices, Inc.
REM     or any copyright holders or contributors may be used to endorse or
REM     promote products derived from this material without specific prior
REM     written permission.
REM

REM 
REM makeoal.bat
REM Generates the OAL files from the MOF files
REM

@echo off

REM need to go out of these directories because we have an issue with too long file names
REM when we compile dash_client_lib\windows\dashapi\..\..\..\..\cim_mof\moffile
setlocal

set cfg=%1
if [%cfg%]==[] set cfg=Release
set cfg=%cfg:"=%

cd ..\..

if not exist install_root md install_root
if not exist install_root\include md install_root\include
if not exist install_root\include\dsdk md install_root\include\dsdk
if not exist install_root\include\dsdk\oal md install_root\include\dsdk\oal

REM copy dashsdk\dash_client_lib\source\common\COALObject.h install_root\include\dsdk\oal
copy dash_client_lib\source\common\COALObject.h install_root\include\dsdk\oal


"install_root\%cfg%\mof2oal" -u -s mof2oal\skel\mof2cpp -m cim_mof\DRI_Schema.mof -o install_root\include\dsdk\oal -w -b dashsdk\classblacklist.txt

cd %old_dir%
endlocal
