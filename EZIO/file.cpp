#include "file.hpp"

namespace EZ {
    EZIO *cdCommand = new file("cd");
    EZIO *lsCommand = new file("ls");
    EZIO *mkCommand = new file("mk");
    EZIO *plotCommand = new file("plot");
    EZIO *tuneCommand = new file("tune");
}