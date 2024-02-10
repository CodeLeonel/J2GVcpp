#include "j2gvc.h"
#include "test.h"

static void testRenderGraph(const char * dotCommands, const char * engine, const char * formatFile, const char * fileName) {

	renderGraph(dotCommands, engine, formatFile, fileName);

}