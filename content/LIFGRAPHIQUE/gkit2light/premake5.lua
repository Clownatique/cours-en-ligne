workspace "gKit"
    configurations { "debug", "release" }

    filter { "configurations:debug" }
        targetdir "bin/debug"
        defines { "DEBUG" }
        symbols "on"
    
    filter { "configurations:release" }
        targetdir "bin/release"
--~ 		defines { "NDEBUG" }
--~ 		defines { "GK_RELEASE" }
        optimize "speed"
        
    filter { "system:linux" }
        cppdialect "c++14"
        buildoptions { "-mtune=native -march=native" }
        buildoptions { "-Wall -Wsign-compare -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable", "-pipe" }
        
    filter { "system:linux" }
        links { "GLEW", "SDL2", "SDL2_image", "GL" }
    
    filter { "system:linux", "configurations:debug" }
        buildoptions { "-g"}
        linkoptions { "-g"}
--~         openmp "off"
    
    filter { "system:linux", "configurations:release" }
--~         openmp "on"
        buildoptions { "-flto"}
        linkoptions { "-flto=auto"}
       
    
    filter { "system:windows", "action:vs*" }
        location "build"
        debugdir "."
        
        system "Windows"
        architecture "x64"
        disablewarnings { "4244", "4305" }
        flags { "MultiProcessorCompile", "NoMinimalRebuild" }
        
        defines { "WIN32", "_USE_MATH_DEFINES", "_CRT_SECURE_NO_WARNINGS" }
        defines { "NOMINMAX" } -- allow std::min() and std::max() in vc++ :(((
        
        cppdialect "c++14"
        openmp "on"
        vectorextensions "avx2"
        floatingpoint "strict"
        exceptionhandling "off"
        
        includedirs { "extern/visual/include" }
        libdirs { "extern/visual/lib" }
        links { "opengl32", "glew32", "SDL2", "SDL2_image", "SDL2main" }
        
        -- beuk, mais necessaire...
        if _ACTION == "vs*" then
            printf("\ncopying dll...")
            if not os.isdir("extern/visual/bin/") then
                printf("[error] no dll...\n")
            end
            os.mkdir("bin")
            os.copyfile("extern/visual/bin/glew32.dll", "bin/glew32.dll")
            os.copyfile("extern/visual/bin/SDL2.dll", "bin/SDL2.dll")
        end
    
    filter { "system:macosx" }
        buildoptions { "-Wno-deprecated-declarations" }
        
        cppdialect "c++14"
        frameworks= "-F /Library/Frameworks/"
        defines { "GK_MACOS" }
        buildoptions { frameworks }
        linkoptions { "-framework OpenGL -framework SDL2 -framework SDL2_image" }
    
    
project "libgkit"
    language "C++"
    kind "StaticLib"
    targetdir "bin"
    includedirs { ".", "src/gKit" }
    files { "src/gKit/*.cpp", "src/gKit/*.h" }
    

 -- description des projets		 
projects = {
    "base",
    "tp"
}

for i, name in ipairs(projects) do
    project (name )
        language "C++"
        kind "ConsoleApp"
        targetdir "bin"
        links { "libgkit" }
        includedirs { ".", "src/gKit" }
        files { "projets/" .. name .. ".cpp" }
end

 -- description des utilitaires
tools= {
    "shader_kit",
    "shader_kit_debug",
    "image_viewer"
}

for i, name in ipairs(tools) do
    project(name)
        language "C++"
        kind "ConsoleApp"
        targetdir "bin"
        links { "libgkit" }
        includedirs { ".", "src/gKit" }
        files { "src/" .. name .. ".cpp" }
end
