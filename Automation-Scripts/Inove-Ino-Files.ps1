$directory = "directory/of/E/files"

for ($i=1; $i -le 24; $i++) 
{
    $path = Join-Path $directory "E$i\*.ino"
    Invoke-Item $path
    Start-Sleep -Seconds 3
}
