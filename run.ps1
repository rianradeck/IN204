param(
    [string]$projectDir = ".\code.cpp"
)

if ($projectDir -eq ".\code.cpp") {
    $exeFile = ".\code.exe"
    $cppFile = Resolve-Path -Path $projectDir
    if (!(Test-Path $exeFile) -or ((Get-Item $cppFile).LastWriteTime -gt (Get-Item $exeFile).LastWriteTime)) {
        if (Test-Path $exeFile) {
            Invoke-Expression "rm $exeFile"
        }
        Write-Host "Compiling $cppFile"
        g++ $cppFile -o $exeFile -std=c++20
    }
    if (Test-Path $exeFile) {
        Write-Host "Running $exeFile"
        & $exeFile
    } else {
        Write-Host "Compilation failed. $exeFile not found."
    }
} else {
    $exeFile = '.\main.exe'

    $projectDir = Resolve-Path -Path $projectDir
    $filesInDir = Get-ChildItem -Path $projectDir -Recurse
    $lastUpdated = $filesInDir | Sort-Object -Property LastWriteTime -Descending | Select-Object -First 1
    if (!(Test-Path $exeFile) -or ((Get-Item $lastUpdated).LastWriteTime -gt (Get-Item $exeFile).LastWriteTime)) {    
        $cppFiles = Get-ChildItem -Path $projectDir -Filter *.cpp -Recurse
        $toCompile = ''
        $mainFile = ''
        foreach ($cppFile in $cppFiles) {
            if ($cppFile.Name -ne 'main.cpp') {
                $toCompile += $cppFile.FullName + ' '
            } else {
                $mainFile = $cppFile.FullName
            }
        }
        $allFiles = $mainFile + ' ' + $toCompile
        $compileCmd = "g++ " + $allFiles + "-o " + $exeFile + " -std=c++20"
        Write-Host "Compiling $projectDir"
        write-host $compileCmd
        if (Test-Path $exeFile) {
            Invoke-Expression "rm $exeFile"
        }
        Invoke-Expression $compileCmd
    }
    if (!(Test-Path $exeFile)) {
        Write-Host "Compilation failed. $exeFile not found."
        return
    }
    Write-Host "Running $exeFile"
    Invoke-Expression $exeFile
}