#ifndef CALLINGCONVENTIONS_HPP
#define CALLINGCONVENTIONS_HPP

#if defined(_MSC_VER)

#ifndef FASTCALL
#define FASTCALL __fastcall
#endif

#ifndef STDCALL
#define STDCALL __stdcall
#endif

#ifndef THISCALL
#define THISCALL __thiscall
#endif

#ifndef FORCEINLINE
#define FORCEINLINE __forceinline
#endif

#elif defined(__GNUC__)

#ifndef FASTCALL
#define FASTCALL __attribute__(fastcall)
#endif

#ifndef STDCALL
#define STDCALL __attribute__(stdcall)
#endif

#ifndef THISCALL
#define THISCALL __attribute__(thiscall)
#endif

#ifndef FORCEINLINE
#define FORCEINLINE __attribute__((always_inline)) inline
#endif

#else

#warning "Unrecognized compiler!"

#endif

#endif