Get-Process "javaw" | Where-Object {$_.ProcessName -eq "javaw" -and $_.MainWindowTitle -match "Arduino"} | ForEach-Object { $_.CloseMainWindow() }
