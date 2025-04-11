#!/bin/bash

# Variables
REMOTE_USER="pi"
REMOTE_HOST="192.168.101.164"
REMOTE_PASS="raspberry"
REMOTE_BASE_DIR="/home/pi/uMyo"
REMOTE_DIR="$REMOTE_BASE_DIR/build"
LOCAL_FILE="build/MuscleNNFirmware.hex"
UPLOAD_SCRIPT="/home/pi/uMyo/upload.sh"

# Transfer the file
sshpass -p "$REMOTE_PASS" scp "$LOCAL_FILE" "$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR"

# Execute the upload script on the remote host
sshpass -p "$REMOTE_PASS" ssh "$REMOTE_USER@$REMOTE_HOST" "cd $REMOTE_BASE_DIR && $UPLOAD_SCRIPT"