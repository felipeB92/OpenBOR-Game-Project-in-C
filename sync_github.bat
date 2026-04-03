@echo off
:: Navega até a unidade D e depois para a pasta do jogo
d:
cd "D:\Felipe\OB\Streets_Of_Rage_ Legacy1.5(2026)\data"

:: Comandos do Git
git add .
git commit -m "Backup Automatico OpenBOR - %date% %time%"
git push origin main

exit