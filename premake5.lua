workspace "cppgame"

    architecture "x64"
    configurations {"Debug", "Release", "Distribution"}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "cppgame"

    kind "SharedLib"
    location "cppgame/"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

    files {"src/core/**.cpp", "src/core/**.hpp"}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines {"GAME_PLATFORM_WINDOWS", "GAME_BUILD_DLL"}

    filter "system:linux"
        cppdialect "C++17"
        pic "on"
        systemversion "latest"

        defines {"GAME_PLATFORM_LINUX", "GAME_BUILD_SO"}

    filter "configurations:Debug"
        defines {"DEBUG", "LOG_ON"}
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines {"RELEASE", "LOG_ON"}
        optimize "On"
        buildoptions "/MD"
    filter "configurations:Release"
        defines {"RELEASE", "LOG_OFF"}
        optimize "On"
        buildoptions "/MD"

 project "game_test"

    kind "ConsoleApp"
    location "game_test/"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

    files {"src/**.cpp", "src/**.hpp"}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines {"GAME_PLATFORM_WINDOWS", "GAME_BUILD_EXE"}

    filter "system:linux"
        cppdialect "C++17"
        pic "on"
        systemversion "latest"

        defines {"GAME_PLATFORM_LINUX", "GAME_BUILD_EXEC"}

    filter "configurations:Debug"
        defines {"DEBUG", "LOG_ON"}
        symbols "On"
        buildoptions "/MTd"

    filter "configurations:Release"
        defines {"RELEASE", "LOG_ON"}
        optimize "On"
        buildoptions "/MT"
    filter "configurations:Release"
        defines {"RELEASE", "LOG_OFF"}
        optimize "On"
        buildoptions "/MT"