@echo off
d:
cd "D:\Felipe\OB\Streets_Of_Rage_ Legacy1.5(2026)\DATA"

:: Adiciona as alterações
git add .

:: Cria o commit com a data
git commit -m "Backup Automatico - %date%"

:: O segredo está aqui: envia da master local para a main do GitHub
git push origin master:main --force

exit