@echo off > dri.mof
FOR %%c in (dri\*.mof) DO echo #pragma include ("%%c") >> dri.mof