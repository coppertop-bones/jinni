#!/bin/bash

# Get the current user's home directory
user_home=$(eval echo ~$USER)

# Copy jinni.dylib to the Microsoft Excel folder in the user's home directory
cp jinni.dylib "${user_home}/Library/Group Containers/UBF8T346G9.Office/"
sudo cp jinni.dylib "/Library/Application Support/Microsoft/"

