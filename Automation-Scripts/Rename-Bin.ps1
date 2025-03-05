$sourceFolderPath = "C:\Users\Zer'O\Desktop\Final_Codes\TRANSPOSITIONING CODES\TRY_2\E"

$destinationFolderPath = "C:\Users\Zer'O\Desktop\BIN FILES"

for ($i=1; $i -le 24; $i++) 
{
    $sourceFilePath = Join-Path $sourceFolderPath "E$i\E$i.ino.esp32da.bin"
    
    $newFileName = "C$i.bin"
    
    $newFilePath = Join-Path $sourceFolderPath "E$i\$newFileName"
    
    Rename-Item $sourceFilePath $newFilePath
    
    Move-Item $newFilePath $destinationFolderPath
    
    Write-Host "File $sourceFilePath has been renamed to $newFileName and moved to $destinationFolderPath"
}
