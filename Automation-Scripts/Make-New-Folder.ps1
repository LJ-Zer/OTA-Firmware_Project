$source = "C:\Users\Zer'O\Desktop\Final_Codes\TRANSPOSITIONING CODES\TRY_2\D"
$dest = "C:\Users\Zer'O\Desktop\Final_Codes\TRANSPOSITIONING CODES\TRY_2\F"

for ($i=1; $i -le 24; $i++) 
{
    $src = Join-Path $source "D$i"
    $dst = Join-Path $dest "F$i"
    New-Item -ItemType Directory -Force $dst
    Copy-Item "$src\*.ino" $dst -Force
    Get-ChildItem $dst -Filter *.ino | ForEach-Object {
    $_ | Rename-Item -NewName ("F$i_D$i" + $_.Extension)
}

}

Write-Host "GOODS NA"
