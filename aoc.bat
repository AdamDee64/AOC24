@echo off
cls

SET SRC_NAME=day-06

SET SRC_FILE=%SRC_NAME%\%SRC_NAME%.c 
SET OUT_PATH=out\
SET OUT_FILE=%SRC_NAME%.exe

SET BASE_PATH=%PATH%
SET CC_PATH=C:\msys64\ucrt64\bin
SET PATH=%CC_PATH%;%PATH%

IF NOT EXIST %OUT_PATH% (
    mkdir %OUT_PATH%
)


IF EXIST %OUT_PATH%%OUT_FILE% (
    del %OUT_PATH%%OUT_FILE%
) 

gcc -Os -Wall %SRC_FILE% -o %OUT_PATH%%SRC_NAME%

IF EXIST %OUT_PATH%%OUT_FILE% (
    %OUT_PATH%%OUT_FILE%
) 

SET PATH=%BASE_PATH%
SET BASE_PATH=
