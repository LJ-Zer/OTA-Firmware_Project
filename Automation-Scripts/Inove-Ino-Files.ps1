$directory = "C:\Users\Zer'O\Desktop\Final_Codes\TRANSPOSITIONING CODES\TRY_2\E"

for ($i=1; $i -le 24; $i++) 
{
    $path = Join-Path $directory "E$i\*.ino"
    Invoke-Item $path
    Start-Sleep -Seconds 3
}
