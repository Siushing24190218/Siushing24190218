name: W Binary L

on:
  workflow_dispatch:
  schedule:
    - cron: "0 0 * * 0" #once per week

# The schedule event can be delayed during periods of high loads of GitHub Actions workflow runs
#
# ┌───────────── minute (0 - 59)
# │ ┌───────────── hour (0 - 23)
# │ │ ┌───────────── day of the month (1 - 31)
# │ │ │ ┌───────────── month (1 - 12 or JAN-DEC)
# │ │ │ │ ┌───────────── day of the week (0 - 6 or SUN-SAT)
# │ │ │ │ │
# │ │ │ │ │
# │ │ │ │ │
# * * * * *

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - uses: actions/checkout@v4
      - name: Setup .NET
        uses: actions/setup-dotnet@v4
        with:
          dotnet-version: 9.0.x

      - name: Publish
        run: dotnet publish -c Release -r linux-x64 "/p:IlcGenerateMstatFile=true;IlcGenerateDgmlFile=true"
        working-directory: ./Source/AssetRipper.GUI.Free/

      - name: List Files
        shell: bash
        run: ls -R ./Source/0Bins/obj/AssetRipper.GUI.Free/Release/

      - name: Upload
        uses: actions/upload-artifact@v4
        with:
          name: Analysis
          path: |
            ./Source/0Bins/obj/AssetRipper.GUI.Free/Release/linux-x64/native/*.dgml.xml
            ./Source/0Bins/obj/AssetRipper.GUI.Free/Release/linux-x64/native/*.mstat
          if-no-files-found: error