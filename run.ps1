$cppFile = ".\code.cpp"
$exeFile = ".\code.exe"

if (!(Test-Path $exeFile) -or ((Get-Item $cppFile).LastWriteTime -gt (Get-Item $exeFile).LastWriteTime)) {
    Write-Host "Compiling code.cpp"
    g++ $cppFile -o $exeFile -std=c++17
}

if (Test-Path $exeFile) {
    Write-Host "Running code.exe"
    & $exeFile
} else {
    Write-Host "Compilation failed. code.exe not found."
}
