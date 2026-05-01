@echo off
d:
:: Agora o comando CD entra direto na pasta DATA
cd "D:\Felipe\OB\Streets_Of_Rage_ Legacy1.5(2026)\DATA"

git add .
git commit -m "Backup Scripts OpenBOR - %date% %time%"
git push origin main

exit