stage0="$1"
stage1="pre$1"
./preproc.exe "$stage0" "$stage1"
./Dict.exe "$stage1" "$2" | echo
