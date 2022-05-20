workspace "cppgame"

    architecture "x64"
    configurations {"Debug", "Release", "Distribution"}

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "deps/glfw"

project "cppgame"

    kind "SharedLib"
    language "C++"
    location "cppgame/"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

    files {"cppgame/src/**.cpp", "cppgame/src/**.h"}
    includedirs{"cppgame/src", "deps/glfw/include", "deps/stb/"}

    links {"GLFW"}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines {"GAME_PLATFORM_WINDOWS", "GAME_BUILD_DLL"}

    filter "configurations:Debug"
        defines {"DEBUG", "LOG_ON"}
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines {"RELEASE", "LOG_ON"}
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Distribution"
        defines {"RELEASE", "LOG_OFF"}
        optimize "On"
        buildoptions "/MD"

 project "game_test"

    kind "ConsoleApp"
    language "C++"
    location "game_test/"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/")

    files {"game_test/src/**.cpp", "game_test/src/**.h"}

    links { "cppgame" }

    includedirs {
        "cppgame/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines {"GAME_PLATFORM_WINDOWS", "GAME_BUILD_EXE"}

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