#ifndef MEMORYDEBUG_HPP
#define MEMORYDEBUG_HPP

#ifdef _DEBUG

#define MY_DBG_NEW new ( _NORMAL_BLOCK, __FILE__, __LINE__ )
#define new MY_DBG_NEW

#endif

#endif // MEMORYDEBUG_HPP