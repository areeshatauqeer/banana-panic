# Visual Studio 2026 Setup Guide

## Step-by-Step Setup Instructions

### Step 1: Install SFML 2.6.2

1. Download SFML 2.6.2 for Visual Studio 2026 (64-bit) from:
   https://www.sfml-dev.org/download.php
   
2. Extract the SFML folder to a location like:
   - `C:\SFML` (recommended)
   - Or `C:\Libraries\SFML-2.6.2`

3. Note the path where you extracted SFML - you'll need it in Step 3.

### Step 2: Open the Project in Visual Studio

1. **Option A: Double-click the project file**
   - Navigate to your project folder
   - Double-click `PlatformerGame.vcxproj`
   - Visual Studio 2026 should open automatically

2. **Option B: Open from Visual Studio**
   - Open Visual Studio 2026
   - Go to **File → Open → Project/Solution**
   - Navigate to your project folder
   - Select `PlatformerGame.vcxproj`
   - Click **Open**

### Step 3: Configure SFML Path

You have two options:

#### Option A: Set Environment Variable (Recommended)

1. **Set SFML_DIR environment variable:**
   - Press `Win + R`, type `sysdm.cpl`, press Enter
   - Go to **Advanced** tab
   - Click **Environment Variables**
   - Under **User variables**, click **New**
   - Variable name: `SFML_DIR`
   - Variable value: Path to your SFML folder (e.g., `C:\SFML`)
   - Click **OK** on all dialogs
   - **Restart Visual Studio** for changes to take effect

#### Option B: Configure in Project Properties

1. In Visual Studio, right-click on **PlatformerGame** in Solution Explorer
2. Select **Properties**
3. In the **Configuration** dropdown, select **All Configurations**
4. In the **Platform** dropdown, select **x64**

5. **Set Include Directory:**
   - Go to **Configuration Properties → C/C++ → General**
   - Find **Additional Include Directories**
   - Click the dropdown arrow → **Edit**
   - Click **New Line** (folder icon)
   - Enter: `C:\SFML\include` (or your SFML path + `\include`)
   - Click **OK**

6. **Set Library Directory:**
   - Go to **Configuration Properties → Linker → General**
   - Find **Additional Library Directories**
   - Click the dropdown arrow → **Edit**
   - Click **New Line** (folder icon)
   - Enter: `C:\SFML\lib` (or your SFML path + `\lib`)
   - Click **OK**

7. Click **OK** to close Properties

### Step 4: Verify Build Configuration

1. Check the toolbar at the top:
   - **Solution Configurations**: Should show **Debug** or **Release**
   - **Solution Platforms**: Should show **x64**
   
2. If x64 is not available:
   - Go to **Build → Configuration Manager**
   - Under **Active solution platform**, click dropdown
   - Select **x64** (or **New** to create it)
   - Click **Close**

### Step 5: Build the Project

1. **First Build:**
   - Go to **Build → Build Solution** (or press `Ctrl + Shift + B`)
   - Wait for compilation to complete
   - Check the **Output** window at the bottom for errors

2. **Common Issues:**
   - **"Cannot open include file 'SFML/...'"**: SFML path not set correctly (see Step 3)
   - **"Unresolved external symbol"**: Missing library directories or wrong configuration
   - **"LNK1104: cannot open file"**: DLLs might be in use, close any running instances

### Step 6: Copy SFML DLLs

After successful build:

1. **Find your output directory:**
   - Usually: `x64\Debug\` or `x64\Release\` in your project folder
   - Or check: **Project Properties → General → Output Directory**

2. **Copy DLLs from SFML:**
   - Go to your SFML folder → `bin` folder
   - For **Debug** build, copy:
     - `sfml-graphics-d-2.dll`
     - `sfml-window-d-2.dll`
     - `sfml-system-d-2.dll`
     - `sfml-audio-d-2.dll`
   - For **Release** build, copy:
     - `sfml-graphics-2.dll`
     - `sfml-window-2.dll`
     - `sfml-system-2.dll`
     - `sfml-audio-2.dll`

3. **Paste DLLs** into your output directory (where the .exe is)

### Step 7: Set Working Directory (For Assets)

1. Right-click **PlatformerGame** in Solution Explorer
2. Select **Properties**
3. Go to **Configuration Properties → Debugging**
4. Set **Working Directory** to: `$(ProjectDir)` or `$(OutDir)`
   - This ensures assets are found relative to the .exe
5. Click **OK**

### Step 8: Run the Game

1. Press **F5** (Start Debugging) or **Ctrl + F5** (Start Without Debugging)
2. The game window should open!

### Quick Reference: Project Structure

```
oop_project/
├── PlatformerGame.vcxproj  ← Project file
├── src/                    ← Source code
│   ├── main.cpp
│   ├── Game.cpp/h
│   ├── Player.cpp/h
│   └── ...
├── x64/                    ← Build output (created after build)
│   └── Debug/ or Release/
│       ├── PlatformerGame.exe
│       ├── *.dll           ← Copy SFML DLLs here
│       └── ...
├── bunny1_stand.png        ← Your assets (should be here)
├── bg_layer1.png
└── ... (all other assets)
```

### Troubleshooting

**Problem: "SFML_DIR is not defined"**
- Solution: Set the environment variable (Step 3, Option A) or configure paths manually (Step 3, Option B)

**Problem: Assets not loading**
- Solution: Make sure all PNG/OGG/TTF files are in the same folder as the .exe
- Or set Working Directory in project properties (Step 7)

**Problem: "Cannot find or open the PDB file"**
- Solution: This is just a warning, not an error. The game should still run.

**Problem: Game crashes on startup**
- Solution: Make sure all SFML DLLs are copied to the output directory
- Check that assets exist in the working directory

**Problem: Build fails with linker errors**
- Solution: 
  1. Verify you're building for x64 (not Win32)
  2. Check that library directories are set correctly
  3. Make sure you're using the correct SFML version (2.6.2)

### Visual Studio Tips

- **Solution Explorer**: View all project files (View → Solution Explorer)
- **Output Window**: See build messages (View → Output)
- **Error List**: See compilation errors (View → Error List)
- **Properties**: Right-click project → Properties to configure settings
- **IntelliSense**: Should work automatically for code completion

### Next Steps

Once the project builds successfully:
1. Run the game and test it
2. Customize game parameters in the source code
3. Add more assets as needed
4. Enjoy your cute platformer! 🎮

---

**Need Help?**
- Check the README.md for game features
- Check SETUP.md for general setup
- Check ASSETS_GUIDE.md for asset requirements

