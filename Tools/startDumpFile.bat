@echo off
chcp 65001 >nul
echo 正在启用Dump...

:: 创建Dump目录（如果不存在）
if not exist "C:\CrashDump" (
    mkdir "C:\CrashDump"
    echo 已创建目录 C:\CrashDump
)

:: 添加注册表配置
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps" /v DumpFolder /t REG_EXPAND_SZ /d "C:\CrashDump" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps" /v DumpType /t REG_DWORD /d 2 /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps" /v DumpCount /t REG_DWORD /d 10 /f

echo Dump已经启用，文件将保存在 C:\CrashDump
pause
@echo on
