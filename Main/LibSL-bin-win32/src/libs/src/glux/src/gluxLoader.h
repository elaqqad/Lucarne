// --------------------------------------------------------
// Author: Sylvain.Lefebvre@sophia.inria.fr
// -------------------------------------------------------- 

#ifndef __GLUX_LOADER__
#define __GLUX_LOADER__

// -------------------------------------------------------- 

#ifndef GLUX_NO_OUTPUT
#include <iostream>
#include <sstream>
#endif 

// --------------------------------------------------------

#include <string>
#include <map>
#include <set>

// --------------------------------------------------------

#define GLUX_NOT_LOADED   -1
#define GLUX_NOT_AVAILABLE 0
#define GLUX_NOT_DEVL      0
#define GLUX_AVAILABLE     1
#define GLUX_DEVL          2

#define GLUX_IS_AVAILABLE(pl) glux_plugin_##pl.isAvailable()
#define GLUX_IS_DEVL(pl)      glux_plugin_##pl.isDevel()
#define GLUX_IS_LOADED        GLUX_IS_AVAILABLE

// -------------------------------------------------------- 

extern const char *g_glux__wglExtensions;

// --------------------------------------------------------

namespace glux
{

  class gluxPlugin;

  void init(int flags,const char *profile);
  void shutdown();
  void registerPlugin(gluxPlugin *pl); 
  bool validateExtension(const std::pair<std::string,gluxPlugin*>& ext,int flags,bool use_profile,const char *profile,const std::set<std::string>& ext_profile,std::stringstream& strout);

} 

// -------------------------------------------------------- 

void gluxInit(int flags,const char *profile);
void gluxInit();           // for backward compatibility
void gluxInit(int flags);  // for backward compatibility
void gluxShutdown();
int  gluxIsAvailable(const char *);
int  gluxIsDevl(const char *); 

// -------------------------------------------------------- 
#endif 
// --------------------------------------------------------
