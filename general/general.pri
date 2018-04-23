CONFIG(debug, debug|release)
{
    win32
    {
        contains(QMAKE_TARGET.arch, x86){
        DESTDIR=../../debug_x86/
        OBJECTS_DIR = ../../temp/uniz_debug_x86/
        MOC_DIR = ../../temp/uniz_debug_x86/
        }
        contains(QMAKE_TARGET.arch, x86_64){
            DESTDIR=../../debug_x64/
            OBJECTS_DIR = ../../temp/uniz_debug_x64/
            MOC_DIR = ../../temp/uniz_debug_x64/
        }
    }
}



CONFIG(release, debug|release){
win32
{
    contains(QMAKE_TARGET.arch, x86){
        DESTDIR=../../release_x86/
        OBJECTS_DIR = ../../temp/uniz_release_x86/
        MOC_DIR = ../../temp/uniz_release_x86/
    }
    contains(QMAKE_TARGET.arch, x86_64){
        DESTDIR=../../release_x64/
        OBJECTS_DIR = ../../temp/uniz_release_x64/
        MOC_DIR = ../../temp/uniz_release_x64/
    }
}
}
