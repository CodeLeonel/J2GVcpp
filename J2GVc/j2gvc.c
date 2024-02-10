#include "j2gvc.h"
#include "cgraph.h"
#include "gvc.h"

void renderGraph(const char* dotCommands, const char* engine, const char* formatFile, const char* fileName) {

	Agraph_t* g;
	GVC_t* gvc;

	/* set up a graphviz context */
	gvc = gvContext();
	g = agmemread(dotCommands);

	gvLayout(gvc, g, engine);
	gvRenderFilename(gvc, g, formatFile, fileName);
	/* Free layout data */
	gvFreeLayout(gvc, g);
	/* Free graph structures */
	agclose(g);

	/* close output file, free context, and return number of errors */
	return (gvFreeContext(gvc));

}