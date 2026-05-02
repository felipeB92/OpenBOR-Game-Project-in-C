@echo off
d:
cd "D:\Felipe\OB\Streets_Of_Rage_ Legacy1.5(2026)\DATA"
git add .
git commit -m "Backup Automatico - %date%"
git push origin main
exit