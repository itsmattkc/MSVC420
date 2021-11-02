/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 2.00.0101 */
/* at Fri May 24 09:43:35 1996
 */
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __hlink_h__
#define __hlink_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHlink_FWD_DEFINED__
#define __IHlink_FWD_DEFINED__
typedef interface IHlink IHlink;
#endif 	/* __IHlink_FWD_DEFINED__ */


#ifndef __IHlinkSite_FWD_DEFINED__
#define __IHlinkSite_FWD_DEFINED__
typedef interface IHlinkSite IHlinkSite;
#endif 	/* __IHlinkSite_FWD_DEFINED__ */


#ifndef __IHlinkTarget_FWD_DEFINED__
#define __IHlinkTarget_FWD_DEFINED__
typedef interface IHlinkTarget IHlinkTarget;
#endif 	/* __IHlinkTarget_FWD_DEFINED__ */


#ifndef __IHlinkFrame_FWD_DEFINED__
#define __IHlinkFrame_FWD_DEFINED__
typedef interface IHlinkFrame IHlinkFrame;
#endif 	/* __IHlinkFrame_FWD_DEFINED__ */


#ifndef __IEnumHLITEM_FWD_DEFINED__
#define __IEnumHLITEM_FWD_DEFINED__
typedef interface IEnumHLITEM IEnumHLITEM;
#endif 	/* __IEnumHLITEM_FWD_DEFINED__ */


#ifndef __IHlinkBrowseContext_FWD_DEFINED__
#define __IHlinkBrowseContext_FWD_DEFINED__
typedef interface IHlinkBrowseContext IHlinkBrowseContext;
#endif 	/* __IHlinkBrowseContext_FWD_DEFINED__ */


/* header files for imported files */
#include "urlmon.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright 1995-1996 Microsoft Corporation. All Rights Reserved.
//
//  File: hlink.h
//
//--------------------------------------------------------------------------

#pragma comment(lib,"uuid.lib")
                                                                              
#ifndef HLINK_H                                                               
#define HLINK_H                                                               
			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

// We temporarily support the old 'source' names                              
#define SID_SHlinkFrame IID_IHlinkFrame                                       
#define IID_IHlinkSource IID_IHlinkTarget                                     
#define IHlinkSource IHlinkTarget                                             
#define IHlinkSourceVtbl IHlinkTargetVtbl                                     
#define LPHLINKSOURCE LPHLINKTARGET                                           
#define GetBoundSource GetBoundTarget                                         
                                                                              
/****************************************************************************/
/**** Error codes                                                        ****/
/****************************************************************************/
#ifndef _HLINK_ERRORS_DEFINED                                                 
#define _HLINK_ERRORS_DEFINED                                                 
#define HLINK_E_FIRST                    (OLE_E_LAST+1)                       
#define HLINK_S_FIRST                    (OLE_S_LAST+1)                       
#define HLINK_S_DONTHIDE                 (HLINK_S_FIRST)                      
#endif //_HLINK_ERRORS_DEFINED                                                
                                                                              
                                                                              
/****************************************************************************/
/**** Hyperlink APIs                                                     ****/
/****************************************************************************/
                                                                              
#if MAC || defined(_MAC)                                                      
#define  cfHyperlink   'HLNK'                                                 
#else                                                                         
#define CFSTR_HYPERLINK         (TEXT("Hyperlink"))                         
#endif                                                                        
                                                                              
                                                                              
STDAPI HlinkCreateFromMoniker(                                                
             IMoniker * pimkTrgt,                                             
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzFriendlyName,                                         
             IHlinkSite * pihlsite,                                           
             DWORD dwSiteData,                                                
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
                                                                              
STDAPI HlinkCreateFromString(                                                 
             LPCWSTR pwzTarget,                                               
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzFriendlyName,                                         
             IHlinkSite * pihlsite,                                           
             DWORD dwSiteData,                                                
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
                                                                              
STDAPI HlinkCreateFromData(                                                   
             IDataObject *piDataObj,                                          
             IHlinkSite * pihlsite,                                           
             DWORD dwSiteData,                                                
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
  																			 
STDAPI HlinkQueryCreateFromData(IDataObject *piDataObj);                      
                                                                              
STDAPI HlinkClone(                                                            
             IHlink * pihl,                                                   
             REFIID riid,                                                     
             IHlinkSite * pihlsiteForClone,                                   
             DWORD dwSiteData,                                                
             void ** ppvObj);                                                 
                                                                              
STDAPI HlinkCreateBrowseContext(                                              
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
                                                                              
STDAPI HlinkNavigateToStringReference(                                        
             LPCWSTR pwzTarget,                                               
             LPCWSTR pwzLocation,                                             
             IHlinkSite * pihlsite,                                           
             DWORD dwSiteData,                                                
             IHlinkFrame *pihlframe,                                          
             DWORD grfHLNF,                                                   
             LPBC pibc,                                                       
             IBindStatusCallback * pibsc,                                     
             IHlinkBrowseContext *pihlbc);                                    
                                                                              
STDAPI HlinkNavigate(                                                         
             IHlink * pihl,                                                   
             IHlinkFrame * pihlframe,                                         
             DWORD grfHLNF,                                                   
             LPBC pbc,                                                        
             IBindStatusCallback * pibsc,                                     
             IHlinkBrowseContext *pihlbc);                                    
                                                                              
STDAPI HlinkOnNavigate(                                                       
             IHlinkFrame * pihlframe,                                         
             IHlinkBrowseContext * pihlbc,                                    
             DWORD grfHLNF,                                                   
             IMoniker * pimkTarget,                                           
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzFriendlyName,                                         
             ULONG * puHLID);                                                 
                                                                              
STDAPI HlinkUpdateStackItem(                                                  
             IHlinkFrame * pihlframe,                                         
             IHlinkBrowseContext * pihlbc,                                    
             ULONG uHLID,                                                     
             IMoniker * pimkTrgt,                                             
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzFriendlyName);                                        
                                                                              
STDAPI HlinkResolveMonikerForData(                                            
             LPMONIKER pimkReference,                                         
             DWORD reserved,                                                  
             LPBC pibc,                                                       
             ULONG cFmtetc,                                                   
             FORMATETC * rgFmtetc,                                            
             IBindStatusCallback * pibsc,                                     
             LPMONIKER pimkBase);                                             
                                                                              
STDAPI HlinkResolveStringForData(                                             
             LPCWSTR pwzReference,                                            
             DWORD reserved,                                                  
             LPBC pibc,                                                       
             ULONG cFmtetc,                                                   
             FORMATETC * rgFmtetc,                                            
             IBindStatusCallback * pibsc,                                     
             LPMONIKER pimkBase);                                             
                                                                              
STDAPI HlinkParseDisplayName(                                                 
             LPBC pibc,                                                       
             LPCWSTR pwzDisplayName,                                          
             BOOL fNoForceAbs,                                                
             ULONG * pcchEaten,                                               
             IMoniker ** ppimk);                                              
                                                                              
STDAPI HlinkCreateExtensionServices(                                          
             LPCWSTR pwzAdditionalHeaders,                                    
             HWND phwnd,                                                      
             LPCWSTR pszUsername,                                             
             LPCWSTR pszPassword,                                             
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
                                                                              
STDAPI OleSaveToStreamEx(                                                     
             IUnknown * piunk,                                                
             IStream * pistm,                                                 
             BOOL fClearDirty);                                               
                                                                              
			/* size is 4 */
typedef 
enum _HLSR
    {	HLSR_HOME	= 0,
	HLSR_SEARCHPAGE	= 1,
	HLSR_HISTORYFOLDER	= 2
    }	HLSR;

                                                                              
STDAPI HlinkSetSpecialReference(                                              
             ULONG uReference,                                                
             LPCWSTR pwzReference);                                           
                                                                              
STDAPI HlinkGetSpecialReference(                                              
             ULONG uReference,                                                
             LPWSTR *ppwzReference);                                          
                                                                              
			/* size is 4 */
typedef 
enum _HLSHORTCUTF
    {	HLSHORTCUTF_DEFAULT	= 0,
	HLSHORTCUTF_DONTACTUALLYCREATE	= 0x1
    }	HLSHORTCUTF;

                                                                              
STDAPI HlinkCreateShortcut(                                                   
             DWORD grfHLSHORTCUTF,                                            
             IHlink *pihl,                                                    
             LPCWSTR pwzDir,                                                  
             LPCWSTR pwzFileName,                                             
             LPWSTR *ppwzShortcutFile,                                        
             DWORD dwReserved);                                               
                                                                              
STDAPI HlinkCreateShortcutFromMoniker(                                        
             DWORD grfHLSHORTCUTF,                                            
             IMoniker *pimkTarget,                                            
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzDir,                                                  
             LPCWSTR pwzFileName,                                             
             LPWSTR *ppwzShortcutFile,                                        
             DWORD dwReserved);                                               
                                                                              
STDAPI HlinkCreateShortcutFromString(                                         
             DWORD grfHLSHORTCUTF,                                            
             LPCWSTR pwzTarget,                                               
             LPCWSTR pwzLocation,                                             
             LPCWSTR pwzDir,                                                  
             LPCWSTR pwzFileName,                                             
             LPWSTR *ppwzShortcutFile,                                        
             DWORD dwReserved);                                               
                                                                              
STDAPI HlinkResolveShortcut(                                                  
             LPCWSTR pwzShortcutFileName,                                     
             IHlinkSite * pihlsite,                                           
             DWORD dwSiteData,                                                
             IUnknown * piunkOuter,                                           
             REFIID riid,                                                     
             void ** ppvObj);                                                 
                                                                              
STDAPI HlinkResolveShortcutToMoniker(                                         
             LPCWSTR pwzShortcutFileName,                                     
             IMoniker **ppimkTarget,                                          
             LPWSTR *ppwzLocation);                                           
                                                                              
STDAPI HlinkResolveShortcutToString(                                          
             LPCWSTR pwzShortcutFileName,                                     
             LPWSTR *ppwzTarget,                                              
             LPWSTR *ppwzLocation);                                           
                                                                              
                                                                              
 STDAPI HlinkIsShortcut(LPCWSTR pwzFileName);                                 
                                                                              
                                                                              
STDAPI HlinkGetValueFromParams(                                               
             LPCWSTR pwzParams,                                               
             LPCWSTR pwzName,                                                 
             LPWSTR *ppwzValue);                                              
  																			 
  																			 
			/* size is 4 */
typedef 
enum _HLTRANSLATEF
    {	HLTRANSLATEF_DEFAULT	= 0,
	HLTRANSLATEF_DONTAPPLYDEFAULTPREFIX	= 0x1
    }	HLTRANSLATEF;

  																			 
STDAPI HlinkTranslateURL(                                                     
             LPCWSTR pwzURL,                                                  
             DWORD grfFlags,                                                  
             LPWSTR *ppwzTranslatedURL);                                      
                                                                              
                                                                              
                                                                              
/****************************************************************************/
/**** Hyperlink interface definitions                                    ****/
/****************************************************************************/
                                                                              
#ifndef _LPHLINK_DEFINED
#define _LPHLINK_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IHlink_INTERFACE_DEFINED__
#define __IHlink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlink
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object] */ 


			/* size is 4 */
typedef /* [unique] */ IHlink __RPC_FAR *LPHLINK;

			/* size is 4 */
typedef 
enum __MIDL_IHlink_0001
    {	HLNF_INTERNALJUMP	= 0x1,
	HLNF_OPENINNEWWINDOW	= 0x2,
	HLNF_NAVIGATINGBACK	= 0x4,
	HLNF_NAVIGATINGFORWARD	= 0x8,
	HLNF_NAVIGATINGTOSTACKITEM	= 0x10,
	HLNF_CREATENOHISTORY	= 0x20,
	HLNF_HIDENONWEBTOOLBARS	= 0x40,
	HLNF_DONTMERGEUI	= 0x80
    }	HLNF;

			/* size is 4 */
typedef 
enum __MIDL_IHlink_0002
    {	HLINKGETREF_DEFAULT	= 0,
	HLINKGETREF_ABSOLUTE	= 1,
	HLINKGETREF_RELATIVE	= 2
    }	HLINKGETREF;

			/* size is 4 */
typedef 
enum __MIDL_IHlink_0003
    {	HLFNAMEF_DEFAULT	= 0,
	HLFNAMEF_TRYCACHE	= 0x1,
	HLFNAMEF_TRYPRETTYTARGET	= 0x2,
	HLFNAMEF_TRYFULLTARGET	= 0x4,
	HLFNAMEF_TRYWIN95SHORTCUT	= 0x8
    }	HLFNAMEF;

			/* size is 4 */
typedef 
enum __MIDL_IHlink_0004
    {	HLINKMISC_RELATIVE	= 0x1
    }	HLINKMISC;

			/* size is 4 */
typedef 
enum __MIDL_IHlink_0005
    {	HLINKSETF_TARGET	= 1,
	HLINKSETF_LOCATION	= 2
    }	HLINKSETF;


EXTERN_C const IID IID_IHlink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlink : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetHlinkSite( 
            /* [unique][in] */ IHlinkSite __RPC_FAR *pihlSite,
            /* [in] */ DWORD dwSiteData) = 0;
        
        virtual HRESULT __stdcall GetHlinkSite( 
            /* [out] */ IHlinkSite __RPC_FAR *__RPC_FAR *ppihlSite,
            /* [out] */ DWORD __RPC_FAR *pdwSiteData) = 0;
        
        virtual HRESULT __stdcall SetMonikerReference( 
            /* [in] */ DWORD grfHLSETF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation) = 0;
        
        virtual HRESULT __stdcall GetMonikerReference( 
            /* [in] */ DWORD dwWhichRef,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkTarget,
            /* [out] */ LPWSTR __RPC_FAR *ppwzLocation) = 0;
        
        virtual HRESULT __stdcall SetStringReference( 
            /* [in] */ DWORD grfHLSETF,
            /* [unique][in] */ LPCWSTR pwzTarget,
            /* [unique][in] */ LPCWSTR pwzLocation) = 0;
        
        virtual HRESULT __stdcall GetStringReference( 
            /* [in] */ DWORD dwWhichRef,
            /* [out] */ LPWSTR __RPC_FAR *ppwzTarget,
            /* [out] */ LPWSTR __RPC_FAR *ppwzLocation) = 0;
        
        virtual HRESULT __stdcall SetFriendlyName( 
            /* [unique][in] */ LPCWSTR pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall GetFriendlyName( 
            /* [in] */ DWORD grfHLFNAMEF,
            /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall SetTargetFrameName( 
            /* [unique][in] */ LPCWSTR pwzTargetFrameName) = 0;
        
        virtual HRESULT __stdcall GetTargetFrameName( 
            /* [out] */ LPWSTR __RPC_FAR *ppwzTargetFrameName) = 0;
        
        virtual HRESULT __stdcall GetMiscStatus( 
            /* [out] */ DWORD __RPC_FAR *pdwStatus) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPBC pibc,
            /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc) = 0;
        
        virtual HRESULT __stdcall SetAdditionalParams( 
            /* [unique][in] */ LPCWSTR pwzAdditionalParams) = 0;
        
        virtual HRESULT __stdcall GetAdditionalParams( 
            /* [out] */ LPWSTR __RPC_FAR *ppwzAdditionalParams) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IHlink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IHlink __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IHlink __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetHlinkSite )( 
            IHlink __RPC_FAR * This,
            /* [unique][in] */ IHlinkSite __RPC_FAR *pihlSite,
            /* [in] */ DWORD dwSiteData);
        
        HRESULT ( __stdcall __RPC_FAR *GetHlinkSite )( 
            IHlink __RPC_FAR * This,
            /* [out] */ IHlinkSite __RPC_FAR *__RPC_FAR *ppihlSite,
            /* [out] */ DWORD __RPC_FAR *pdwSiteData);
        
        HRESULT ( __stdcall __RPC_FAR *SetMonikerReference )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD grfHLSETF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation);
        
        HRESULT ( __stdcall __RPC_FAR *GetMonikerReference )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD dwWhichRef,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkTarget,
            /* [out] */ LPWSTR __RPC_FAR *ppwzLocation);
        
        HRESULT ( __stdcall __RPC_FAR *SetStringReference )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD grfHLSETF,
            /* [unique][in] */ LPCWSTR pwzTarget,
            /* [unique][in] */ LPCWSTR pwzLocation);
        
        HRESULT ( __stdcall __RPC_FAR *GetStringReference )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD dwWhichRef,
            /* [out] */ LPWSTR __RPC_FAR *ppwzTarget,
            /* [out] */ LPWSTR __RPC_FAR *ppwzLocation);
        
        HRESULT ( __stdcall __RPC_FAR *SetFriendlyName )( 
            IHlink __RPC_FAR * This,
            /* [unique][in] */ LPCWSTR pwzFriendlyName);
        
        HRESULT ( __stdcall __RPC_FAR *GetFriendlyName )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD grfHLFNAMEF,
            /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName);
        
        HRESULT ( __stdcall __RPC_FAR *SetTargetFrameName )( 
            IHlink __RPC_FAR * This,
            /* [unique][in] */ LPCWSTR pwzTargetFrameName);
        
        HRESULT ( __stdcall __RPC_FAR *GetTargetFrameName )( 
            IHlink __RPC_FAR * This,
            /* [out] */ LPWSTR __RPC_FAR *ppwzTargetFrameName);
        
        HRESULT ( __stdcall __RPC_FAR *GetMiscStatus )( 
            IHlink __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwStatus);
        
        HRESULT ( __stdcall __RPC_FAR *Navigate )( 
            IHlink __RPC_FAR * This,
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPBC pibc,
            /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);
        
        HRESULT ( __stdcall __RPC_FAR *SetAdditionalParams )( 
            IHlink __RPC_FAR * This,
            /* [unique][in] */ LPCWSTR pwzAdditionalParams);
        
        HRESULT ( __stdcall __RPC_FAR *GetAdditionalParams )( 
            IHlink __RPC_FAR * This,
            /* [out] */ LPWSTR __RPC_FAR *ppwzAdditionalParams);
        
    } IHlinkVtbl;

    interface IHlink
    {
        CONST_VTBL struct IHlinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlink_SetHlinkSite(This,pihlSite,dwSiteData)	\
    (This)->lpVtbl -> SetHlinkSite(This,pihlSite,dwSiteData)

#define IHlink_GetHlinkSite(This,ppihlSite,pdwSiteData)	\
    (This)->lpVtbl -> GetHlinkSite(This,ppihlSite,pdwSiteData)

#define IHlink_SetMonikerReference(This,grfHLSETF,pimkTarget,pwzLocation)	\
    (This)->lpVtbl -> SetMonikerReference(This,grfHLSETF,pimkTarget,pwzLocation)

#define IHlink_GetMonikerReference(This,dwWhichRef,ppimkTarget,ppwzLocation)	\
    (This)->lpVtbl -> GetMonikerReference(This,dwWhichRef,ppimkTarget,ppwzLocation)

#define IHlink_SetStringReference(This,grfHLSETF,pwzTarget,pwzLocation)	\
    (This)->lpVtbl -> SetStringReference(This,grfHLSETF,pwzTarget,pwzLocation)

#define IHlink_GetStringReference(This,dwWhichRef,ppwzTarget,ppwzLocation)	\
    (This)->lpVtbl -> GetStringReference(This,dwWhichRef,ppwzTarget,ppwzLocation)

#define IHlink_SetFriendlyName(This,pwzFriendlyName)	\
    (This)->lpVtbl -> SetFriendlyName(This,pwzFriendlyName)

#define IHlink_GetFriendlyName(This,grfHLFNAMEF,ppwzFriendlyName)	\
    (This)->lpVtbl -> GetFriendlyName(This,grfHLFNAMEF,ppwzFriendlyName)

#define IHlink_SetTargetFrameName(This,pwzTargetFrameName)	\
    (This)->lpVtbl -> SetTargetFrameName(This,pwzTargetFrameName)

#define IHlink_GetTargetFrameName(This,ppwzTargetFrameName)	\
    (This)->lpVtbl -> GetTargetFrameName(This,ppwzTargetFrameName)

#define IHlink_GetMiscStatus(This,pdwStatus)	\
    (This)->lpVtbl -> GetMiscStatus(This,pdwStatus)

#define IHlink_Navigate(This,grfHLNF,pibc,pibsc,pihlbc)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pibc,pibsc,pihlbc)

#define IHlink_SetAdditionalParams(This,pwzAdditionalParams)	\
    (This)->lpVtbl -> SetAdditionalParams(This,pwzAdditionalParams)

#define IHlink_GetAdditionalParams(This,ppwzAdditionalParams)	\
    (This)->lpVtbl -> GetAdditionalParams(This,ppwzAdditionalParams)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlink_SetHlinkSite_Proxy( 
    IHlink __RPC_FAR * This,
    /* [unique][in] */ IHlinkSite __RPC_FAR *pihlSite,
    /* [in] */ DWORD dwSiteData);


void __RPC_STUB IHlink_SetHlinkSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetHlinkSite_Proxy( 
    IHlink __RPC_FAR * This,
    /* [out] */ IHlinkSite __RPC_FAR *__RPC_FAR *ppihlSite,
    /* [out] */ DWORD __RPC_FAR *pdwSiteData);


void __RPC_STUB IHlink_GetHlinkSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_SetMonikerReference_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD grfHLSETF,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation);


void __RPC_STUB IHlink_SetMonikerReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetMonikerReference_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD dwWhichRef,
    /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkTarget,
    /* [out] */ LPWSTR __RPC_FAR *ppwzLocation);


void __RPC_STUB IHlink_GetMonikerReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_SetStringReference_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD grfHLSETF,
    /* [unique][in] */ LPCWSTR pwzTarget,
    /* [unique][in] */ LPCWSTR pwzLocation);


void __RPC_STUB IHlink_SetStringReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetStringReference_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD dwWhichRef,
    /* [out] */ LPWSTR __RPC_FAR *ppwzTarget,
    /* [out] */ LPWSTR __RPC_FAR *ppwzLocation);


void __RPC_STUB IHlink_GetStringReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_SetFriendlyName_Proxy( 
    IHlink __RPC_FAR * This,
    /* [unique][in] */ LPCWSTR pwzFriendlyName);


void __RPC_STUB IHlink_SetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetFriendlyName_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD grfHLFNAMEF,
    /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName);


void __RPC_STUB IHlink_GetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_SetTargetFrameName_Proxy( 
    IHlink __RPC_FAR * This,
    /* [unique][in] */ LPCWSTR pwzTargetFrameName);


void __RPC_STUB IHlink_SetTargetFrameName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetTargetFrameName_Proxy( 
    IHlink __RPC_FAR * This,
    /* [out] */ LPWSTR __RPC_FAR *ppwzTargetFrameName);


void __RPC_STUB IHlink_GetTargetFrameName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetMiscStatus_Proxy( 
    IHlink __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwStatus);


void __RPC_STUB IHlink_GetMiscStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_Navigate_Proxy( 
    IHlink __RPC_FAR * This,
    /* [in] */ DWORD grfHLNF,
    /* [unique][in] */ LPBC pibc,
    /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
    /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);


void __RPC_STUB IHlink_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_SetAdditionalParams_Proxy( 
    IHlink __RPC_FAR * This,
    /* [unique][in] */ LPCWSTR pwzAdditionalParams);


void __RPC_STUB IHlink_SetAdditionalParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlink_GetAdditionalParams_Proxy( 
    IHlink __RPC_FAR * This,
    /* [out] */ LPWSTR __RPC_FAR *ppwzAdditionalParams);


void __RPC_STUB IHlink_GetAdditionalParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHlink_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0080
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKSITE_DEFINED
#define _LPHLINKSITE_DEFINED
EXTERN_C const GUID SID_SContainer;


extern RPC_IF_HANDLE __MIDL__intf_0080_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0080_v0_0_s_ifspec;

#ifndef __IHlinkSite_INTERFACE_DEFINED__
#define __IHlinkSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkSite
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object] */ 


			/* size is 4 */
typedef /* [unique] */ IHlinkSite __RPC_FAR *LPHLINKSITE;

			/* size is 4 */
typedef 
enum __MIDL_IHlinkSite_0001
    {	HLINKWHICHMK_CONTAINER	= 1,
	HLINKWHICHMK_BASE	= 2
    }	HLINKWHICHMK;


EXTERN_C const IID IID_IHlinkSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryService( 
            /* [in] */ DWORD dwSiteData,
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwAssign,
            /* [in] */ DWORD dwWhich,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimk) = 0;
        
        virtual HRESULT __stdcall ReadyToNavigate( 
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT __stdcall OnNavigationComplete( 
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwreserved,
            /* [in] */ HRESULT hrError,
            /* [in] */ LPCWSTR pwzError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkSiteVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IHlinkSite __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IHlinkSite __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IHlinkSite __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *QueryService )( 
            IHlinkSite __RPC_FAR * This,
            /* [in] */ DWORD dwSiteData,
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk);
        
        HRESULT ( __stdcall __RPC_FAR *GetMoniker )( 
            IHlinkSite __RPC_FAR * This,
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwAssign,
            /* [in] */ DWORD dwWhich,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimk);
        
        HRESULT ( __stdcall __RPC_FAR *ReadyToNavigate )( 
            IHlinkSite __RPC_FAR * This,
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( __stdcall __RPC_FAR *OnNavigationComplete )( 
            IHlinkSite __RPC_FAR * This,
            /* [in] */ DWORD dwSiteData,
            /* [in] */ DWORD dwreserved,
            /* [in] */ HRESULT hrError,
            /* [in] */ LPCWSTR pwzError);
        
    } IHlinkSiteVtbl;

    interface IHlinkSite
    {
        CONST_VTBL struct IHlinkSiteVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkSite_QueryService(This,dwSiteData,guidService,riid,ppiunk)	\
    (This)->lpVtbl -> QueryService(This,dwSiteData,guidService,riid,ppiunk)

#define IHlinkSite_GetMoniker(This,dwSiteData,dwAssign,dwWhich,ppimk)	\
    (This)->lpVtbl -> GetMoniker(This,dwSiteData,dwAssign,dwWhich,ppimk)

#define IHlinkSite_ReadyToNavigate(This,dwSiteData,dwReserved)	\
    (This)->lpVtbl -> ReadyToNavigate(This,dwSiteData,dwReserved)

#define IHlinkSite_OnNavigationComplete(This,dwSiteData,dwreserved,hrError,pwzError)	\
    (This)->lpVtbl -> OnNavigationComplete(This,dwSiteData,dwreserved,hrError,pwzError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkSite_QueryService_Proxy( 
    IHlinkSite __RPC_FAR * This,
    /* [in] */ DWORD dwSiteData,
    /* [in] */ REFGUID guidService,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk);


void __RPC_STUB IHlinkSite_QueryService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_GetMoniker_Proxy( 
    IHlinkSite __RPC_FAR * This,
    /* [in] */ DWORD dwSiteData,
    /* [in] */ DWORD dwAssign,
    /* [in] */ DWORD dwWhich,
    /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimk);


void __RPC_STUB IHlinkSite_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_ReadyToNavigate_Proxy( 
    IHlinkSite __RPC_FAR * This,
    /* [in] */ DWORD dwSiteData,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IHlinkSite_ReadyToNavigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_OnNavigationComplete_Proxy( 
    IHlinkSite __RPC_FAR * This,
    /* [in] */ DWORD dwSiteData,
    /* [in] */ DWORD dwreserved,
    /* [in] */ HRESULT hrError,
    /* [in] */ LPCWSTR pwzError);


void __RPC_STUB IHlinkSite_OnNavigationComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHlinkSite_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0081
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKTARGET_DEFINED
#define _LPHLINKTARGET_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0081_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0081_v0_0_s_ifspec;

#ifndef __IHlinkTarget_INTERFACE_DEFINED__
#define __IHlinkTarget_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkTarget
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object] */ 


			/* size is 4 */
typedef /* [unique] */ IHlinkTarget __RPC_FAR *LPHLINKTARGET;


EXTERN_C const IID IID_IHlinkTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkTarget : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetBrowseContext( 
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc) = 0;
        
        virtual HRESULT __stdcall GetBrowseContext( 
            /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPCWSTR pwzJumpLocation) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [in] */ DWORD dwAssign,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkLocation) = 0;
        
        virtual HRESULT __stdcall GetFriendlyName( 
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkTargetVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IHlinkTarget __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IHlinkTarget __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IHlinkTarget __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetBrowseContext )( 
            IHlinkTarget __RPC_FAR * This,
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);
        
        HRESULT ( __stdcall __RPC_FAR *GetBrowseContext )( 
            IHlinkTarget __RPC_FAR * This,
            /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc);
        
        HRESULT ( __stdcall __RPC_FAR *Navigate )( 
            IHlinkTarget __RPC_FAR * This,
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPCWSTR pwzJumpLocation);
        
        HRESULT ( __stdcall __RPC_FAR *GetMoniker )( 
            IHlinkTarget __RPC_FAR * This,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [in] */ DWORD dwAssign,
            /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkLocation);
        
        HRESULT ( __stdcall __RPC_FAR *GetFriendlyName )( 
            IHlinkTarget __RPC_FAR * This,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName);
        
    } IHlinkTargetVtbl;

    interface IHlinkTarget
    {
        CONST_VTBL struct IHlinkTargetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkTarget_SetBrowseContext(This,pihlbc)	\
    (This)->lpVtbl -> SetBrowseContext(This,pihlbc)

#define IHlinkTarget_GetBrowseContext(This,ppihlbc)	\
    (This)->lpVtbl -> GetBrowseContext(This,ppihlbc)

#define IHlinkTarget_Navigate(This,grfHLNF,pwzJumpLocation)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pwzJumpLocation)

#define IHlinkTarget_GetMoniker(This,pwzLocation,dwAssign,ppimkLocation)	\
    (This)->lpVtbl -> GetMoniker(This,pwzLocation,dwAssign,ppimkLocation)

#define IHlinkTarget_GetFriendlyName(This,pwzLocation,ppwzFriendlyName)	\
    (This)->lpVtbl -> GetFriendlyName(This,pwzLocation,ppwzFriendlyName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkTarget_SetBrowseContext_Proxy( 
    IHlinkTarget __RPC_FAR * This,
    /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);


void __RPC_STUB IHlinkTarget_SetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetBrowseContext_Proxy( 
    IHlinkTarget __RPC_FAR * This,
    /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc);


void __RPC_STUB IHlinkTarget_GetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_Navigate_Proxy( 
    IHlinkTarget __RPC_FAR * This,
    /* [in] */ DWORD grfHLNF,
    /* [unique][in] */ LPCWSTR pwzJumpLocation);


void __RPC_STUB IHlinkTarget_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetMoniker_Proxy( 
    IHlinkTarget __RPC_FAR * This,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [in] */ DWORD dwAssign,
    /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppimkLocation);


void __RPC_STUB IHlinkTarget_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetFriendlyName_Proxy( 
    IHlinkTarget __RPC_FAR * This,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [out] */ LPWSTR __RPC_FAR *ppwzFriendlyName);


void __RPC_STUB IHlinkTarget_GetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHlinkTarget_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0082
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKFRAME_DEFINED
#define _LPHLINKFRAME_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0082_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0082_v0_0_s_ifspec;

#ifndef __IHlinkFrame_INTERFACE_DEFINED__
#define __IHlinkFrame_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkFrame
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object] */ 


			/* size is 4 */
typedef /* [unique] */ IHlinkFrame __RPC_FAR *LPHLINKFRAME;


EXTERN_C const IID IID_IHlinkFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkFrame : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetBrowseContext( 
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc) = 0;
        
        virtual HRESULT __stdcall GetBrowseContext( 
            /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPBC pbc,
            /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
            /* [unique][in] */ IHlink __RPC_FAR *pihlNavigate) = 0;
        
        virtual HRESULT __stdcall OnNavigate( 
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName,
            /* [in] */ DWORD dwreserved) = 0;
        
        virtual HRESULT __stdcall UpdateHlink( 
            /* [in] */ ULONG uHLID,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkFrameVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IHlinkFrame __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IHlinkFrame __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IHlinkFrame __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *SetBrowseContext )( 
            IHlinkFrame __RPC_FAR * This,
            /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);
        
        HRESULT ( __stdcall __RPC_FAR *GetBrowseContext )( 
            IHlinkFrame __RPC_FAR * This,
            /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc);
        
        HRESULT ( __stdcall __RPC_FAR *Navigate )( 
            IHlinkFrame __RPC_FAR * This,
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ LPBC pbc,
            /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
            /* [unique][in] */ IHlink __RPC_FAR *pihlNavigate);
        
        HRESULT ( __stdcall __RPC_FAR *OnNavigate )( 
            IHlinkFrame __RPC_FAR * This,
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName,
            /* [in] */ DWORD dwreserved);
        
        HRESULT ( __stdcall __RPC_FAR *UpdateHlink )( 
            IHlinkFrame __RPC_FAR * This,
            /* [in] */ ULONG uHLID,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName);
        
    } IHlinkFrameVtbl;

    interface IHlinkFrame
    {
        CONST_VTBL struct IHlinkFrameVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkFrame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkFrame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkFrame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkFrame_SetBrowseContext(This,pihlbc)	\
    (This)->lpVtbl -> SetBrowseContext(This,pihlbc)

#define IHlinkFrame_GetBrowseContext(This,ppihlbc)	\
    (This)->lpVtbl -> GetBrowseContext(This,ppihlbc)

#define IHlinkFrame_Navigate(This,grfHLNF,pbc,pibsc,pihlNavigate)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pbc,pibsc,pihlNavigate)

#define IHlinkFrame_OnNavigate(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,dwreserved)	\
    (This)->lpVtbl -> OnNavigate(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,dwreserved)

#define IHlinkFrame_UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkFrame_SetBrowseContext_Proxy( 
    IHlinkFrame __RPC_FAR * This,
    /* [unique][in] */ IHlinkBrowseContext __RPC_FAR *pihlbc);


void __RPC_STUB IHlinkFrame_SetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_GetBrowseContext_Proxy( 
    IHlinkFrame __RPC_FAR * This,
    /* [out] */ IHlinkBrowseContext __RPC_FAR *__RPC_FAR *ppihlbc);


void __RPC_STUB IHlinkFrame_GetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_Navigate_Proxy( 
    IHlinkFrame __RPC_FAR * This,
    /* [in] */ DWORD grfHLNF,
    /* [unique][in] */ LPBC pbc,
    /* [unique][in] */ IBindStatusCallback __RPC_FAR *pibsc,
    /* [unique][in] */ IHlink __RPC_FAR *pihlNavigate);


void __RPC_STUB IHlinkFrame_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_OnNavigate_Proxy( 
    IHlinkFrame __RPC_FAR * This,
    /* [in] */ DWORD grfHLNF,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [unique][in] */ LPCWSTR pwzFriendlyName,
    /* [in] */ DWORD dwreserved);


void __RPC_STUB IHlinkFrame_OnNavigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_UpdateHlink_Proxy( 
    IHlinkFrame __RPC_FAR * This,
    /* [in] */ ULONG uHLID,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [unique][in] */ LPCWSTR pwzFriendlyName);


void __RPC_STUB IHlinkFrame_UpdateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHlinkFrame_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0083
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPENUMHLITEM_DEFINED
#define _LPENUMHLITEM_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0083_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0083_v0_0_s_ifspec;

#ifndef __IEnumHLITEM_INTERFACE_DEFINED__
#define __IEnumHLITEM_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumHLITEM
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object][local] */ 


			/* size is 4 */
typedef /* [unique] */ IEnumHLITEM __RPC_FAR *LPENUMHLITEM;

			/* size is 8 */
typedef struct  tagHLITEM
    {
    ULONG uHLID;
    LPWSTR pwzFriendlyName;
    }	HLITEM;

			/* size is 4 */
typedef /* [unique] */ HLITEM __RPC_FAR *LPHLITEM;


EXTERN_C const IID IID_IEnumHLITEM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumHLITEM : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Next( 
            /* [in] */ ULONG celt,
            /* [out] */ HLITEM __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumHLITEMVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IEnumHLITEM __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IEnumHLITEM __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IEnumHLITEM __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Next )( 
            IEnumHLITEM __RPC_FAR * This,
            /* [in] */ ULONG celt,
            /* [out] */ HLITEM __RPC_FAR *rgelt,
            /* [out] */ ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( __stdcall __RPC_FAR *Skip )( 
            IEnumHLITEM __RPC_FAR * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( __stdcall __RPC_FAR *Reset )( 
            IEnumHLITEM __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Clone )( 
            IEnumHLITEM __RPC_FAR * This,
            /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem);
        
    } IEnumHLITEMVtbl;

    interface IEnumHLITEM
    {
        CONST_VTBL struct IEnumHLITEMVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumHLITEM_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumHLITEM_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumHLITEM_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumHLITEM_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumHLITEM_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumHLITEM_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumHLITEM_Clone(This,ppienumhlitem)	\
    (This)->lpVtbl -> Clone(This,ppienumhlitem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IEnumHLITEM_Next_Proxy( 
    IEnumHLITEM __RPC_FAR * This,
    /* [in] */ ULONG celt,
    /* [out] */ HLITEM __RPC_FAR *rgelt,
    /* [out] */ ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumHLITEM_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Skip_Proxy( 
    IEnumHLITEM __RPC_FAR * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumHLITEM_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Reset_Proxy( 
    IEnumHLITEM __RPC_FAR * This);


void __RPC_STUB IEnumHLITEM_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Clone_Proxy( 
    IEnumHLITEM __RPC_FAR * This,
    /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem);


void __RPC_STUB IEnumHLITEM_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumHLITEM_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0084
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKBROWSECONTEXT_DEFINED
#define _LPHLINKBROWSECONTEXT_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0084_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0084_v0_0_s_ifspec;

#ifndef __IHlinkBrowseContext_INTERFACE_DEFINED__
#define __IHlinkBrowseContext_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkBrowseContext
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [unique][uuid][object][local] */ 


			/* size is 4 */
typedef /* [unique] */ IHlinkBrowseContext __RPC_FAR *LPHLINKBROWSECONTEXT;

			/* size is 4 */

enum __MIDL_IHlinkBrowseContext_0001
    {	HLTB_DOCKEDLEFT	= 0,
	HLTB_DOCKEDTOP	= 1,
	HLTB_DOCKEDRIGHT	= 2,
	HLTB_DOCKEDBOTTOM	= 3,
	HLTB_FLOATING	= 4
    };
			/* size is 20 */
typedef struct  _tagHLTBINFO
    {
    ULONG uDockType;
    RECT rcTbPos;
    }	HLTBINFO;

			/* size is 4 */

enum __MIDL_IHlinkBrowseContext_0002
    {	HLBWIF_HASFRAMEWNDINFO	= 0x1,
	HLBWIF_HASDOCWNDINFO	= 0x2,
	HLBWIF_FRAMEWNDMAXIMIZED	= 0x4,
	HLBWIF_DOCWNDMAXIMIZED	= 0x8,
	HLBWIF_HASWEBTOOLBARINFO	= 0x10
    };
			/* size is 60 */
typedef struct  _tagHLBWINFO
    {
    ULONG cbSize;
    DWORD grfHLBWIF;
    RECT rcFramePos;
    RECT rcDocPos;
    HLTBINFO hltbinfo;
    }	HLBWINFO;

			/* size is 4 */
typedef /* [unique] */ HLBWINFO __RPC_FAR *LPHLBWINFO;

			/* size is 4 */

enum __MIDL_IHlinkBrowseContext_0003
    {	HLID_INVALID	= 0,
	HLID_PREVIOUS	= 0xffffffff,
	HLID_NEXT	= 0xfffffffe,
	HLID_CURRENT	= 0xfffffffd,
	HLID_STACKBOTTOM	= 0xfffffffc,
	HLID_STACKTOP	= 0xfffffffb
    };
			/* size is 4 */

enum __MIDL_IHlinkBrowseContext_0004
    {	HLQF_ISVALID	= 0x1,
	HLQF_ISCURRENT	= 0x2
    };

EXTERN_C const IID IID_IHlinkBrowseContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkBrowseContext : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Register( 
            /* [in] */ DWORD reserved,
            /* [unique][in] */ IUnknown __RPC_FAR *piunk,
            /* [unique][in] */ IMoniker __RPC_FAR *pimk,
            /* [out] */ DWORD __RPC_FAR *pdwRegister) = 0;
        
        virtual HRESULT __stdcall GetObject( 
            /* [unique][in] */ IMoniker __RPC_FAR *pimk,
            /* [in] */ BOOL fBindIfRootRegistered,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk) = 0;
        
        virtual HRESULT __stdcall Revoke( 
            /* [in] */ DWORD dwRegister) = 0;
        
        virtual HRESULT __stdcall SetBrowseWindowInfo( 
            /* [unique][in] */ HLBWINFO __RPC_FAR *phlbwi) = 0;
        
        virtual HRESULT __stdcall GetBrowseWindowInfo( 
            /* [out] */ HLBWINFO __RPC_FAR *phlbwi) = 0;
        
        virtual HRESULT __stdcall SetInitialHlink( 
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall OnNavigateHlink( 
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName,
            /* [out] */ ULONG __RPC_FAR *puHLID) = 0;
        
        virtual HRESULT __stdcall UpdateHlink( 
            /* [in] */ ULONG uHLID,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall EnumNavigationStack( 
            /* [in] */ DWORD dwReserved,
            /* [in] */ DWORD grfHLFNAMEF,
            /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem) = 0;
        
        virtual HRESULT __stdcall QueryHlink( 
            /* [in] */ DWORD grfHLQF,
            /* [in] */ ULONG uHLID) = 0;
        
        virtual HRESULT __stdcall GetHlink( 
            /* [in] */ ULONG uHLID,
            /* [out] */ IHlink __RPC_FAR *__RPC_FAR *ppihl) = 0;
        
        virtual HRESULT __stdcall SetCurrentHlink( 
            /* [in] */ ULONG uHLID) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [unique][in] */ IUnknown __RPC_FAR *piunkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunkObj) = 0;
        
        virtual HRESULT __stdcall Close( 
            /* [in] */ DWORD reserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkBrowseContextVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            IHlinkBrowseContext __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            IHlinkBrowseContext __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Register )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD reserved,
            /* [unique][in] */ IUnknown __RPC_FAR *piunk,
            /* [unique][in] */ IMoniker __RPC_FAR *pimk,
            /* [out] */ DWORD __RPC_FAR *pdwRegister);
        
        HRESULT ( __stdcall __RPC_FAR *GetObject )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [unique][in] */ IMoniker __RPC_FAR *pimk,
            /* [in] */ BOOL fBindIfRootRegistered,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk);
        
        HRESULT ( __stdcall __RPC_FAR *Revoke )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD dwRegister);
        
        HRESULT ( __stdcall __RPC_FAR *SetBrowseWindowInfo )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [unique][in] */ HLBWINFO __RPC_FAR *phlbwi);
        
        HRESULT ( __stdcall __RPC_FAR *GetBrowseWindowInfo )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [out] */ HLBWINFO __RPC_FAR *phlbwi);
        
        HRESULT ( __stdcall __RPC_FAR *SetInitialHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName);
        
        HRESULT ( __stdcall __RPC_FAR *OnNavigateHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD grfHLNF,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName,
            /* [out] */ ULONG __RPC_FAR *puHLID);
        
        HRESULT ( __stdcall __RPC_FAR *UpdateHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ ULONG uHLID,
            /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
            /* [unique][in] */ LPCWSTR pwzLocation,
            /* [unique][in] */ LPCWSTR pwzFriendlyName);
        
        HRESULT ( __stdcall __RPC_FAR *EnumNavigationStack )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD dwReserved,
            /* [in] */ DWORD grfHLFNAMEF,
            /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem);
        
        HRESULT ( __stdcall __RPC_FAR *QueryHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD grfHLQF,
            /* [in] */ ULONG uHLID);
        
        HRESULT ( __stdcall __RPC_FAR *GetHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ ULONG uHLID,
            /* [out] */ IHlink __RPC_FAR *__RPC_FAR *ppihl);
        
        HRESULT ( __stdcall __RPC_FAR *SetCurrentHlink )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ ULONG uHLID);
        
        HRESULT ( __stdcall __RPC_FAR *Clone )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [unique][in] */ IUnknown __RPC_FAR *piunkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunkObj);
        
        HRESULT ( __stdcall __RPC_FAR *Close )( 
            IHlinkBrowseContext __RPC_FAR * This,
            /* [in] */ DWORD reserved);
        
    } IHlinkBrowseContextVtbl;

    interface IHlinkBrowseContext
    {
        CONST_VTBL struct IHlinkBrowseContextVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkBrowseContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkBrowseContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkBrowseContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkBrowseContext_Register(This,reserved,piunk,pimk,pdwRegister)	\
    (This)->lpVtbl -> Register(This,reserved,piunk,pimk,pdwRegister)

#define IHlinkBrowseContext_GetObject(This,pimk,fBindIfRootRegistered,ppiunk)	\
    (This)->lpVtbl -> GetObject(This,pimk,fBindIfRootRegistered,ppiunk)

#define IHlinkBrowseContext_Revoke(This,dwRegister)	\
    (This)->lpVtbl -> Revoke(This,dwRegister)

#define IHlinkBrowseContext_SetBrowseWindowInfo(This,phlbwi)	\
    (This)->lpVtbl -> SetBrowseWindowInfo(This,phlbwi)

#define IHlinkBrowseContext_GetBrowseWindowInfo(This,phlbwi)	\
    (This)->lpVtbl -> GetBrowseWindowInfo(This,phlbwi)

#define IHlinkBrowseContext_SetInitialHlink(This,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> SetInitialHlink(This,pimkTarget,pwzLocation,pwzFriendlyName)

#define IHlinkBrowseContext_OnNavigateHlink(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,puHLID)	\
    (This)->lpVtbl -> OnNavigateHlink(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,puHLID)

#define IHlinkBrowseContext_UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)

#define IHlinkBrowseContext_EnumNavigationStack(This,dwReserved,grfHLFNAMEF,ppienumhlitem)	\
    (This)->lpVtbl -> EnumNavigationStack(This,dwReserved,grfHLFNAMEF,ppienumhlitem)

#define IHlinkBrowseContext_QueryHlink(This,grfHLQF,uHLID)	\
    (This)->lpVtbl -> QueryHlink(This,grfHLQF,uHLID)

#define IHlinkBrowseContext_GetHlink(This,uHLID,ppihl)	\
    (This)->lpVtbl -> GetHlink(This,uHLID,ppihl)

#define IHlinkBrowseContext_SetCurrentHlink(This,uHLID)	\
    (This)->lpVtbl -> SetCurrentHlink(This,uHLID)

#define IHlinkBrowseContext_Clone(This,piunkOuter,riid,ppiunkObj)	\
    (This)->lpVtbl -> Clone(This,piunkOuter,riid,ppiunkObj)

#define IHlinkBrowseContext_Close(This,reserved)	\
    (This)->lpVtbl -> Close(This,reserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkBrowseContext_Register_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD reserved,
    /* [unique][in] */ IUnknown __RPC_FAR *piunk,
    /* [unique][in] */ IMoniker __RPC_FAR *pimk,
    /* [out] */ DWORD __RPC_FAR *pdwRegister);


void __RPC_STUB IHlinkBrowseContext_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetObject_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [unique][in] */ IMoniker __RPC_FAR *pimk,
    /* [in] */ BOOL fBindIfRootRegistered,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunk);


void __RPC_STUB IHlinkBrowseContext_GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Revoke_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD dwRegister);


void __RPC_STUB IHlinkBrowseContext_Revoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetBrowseWindowInfo_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [unique][in] */ HLBWINFO __RPC_FAR *phlbwi);


void __RPC_STUB IHlinkBrowseContext_SetBrowseWindowInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetBrowseWindowInfo_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [out] */ HLBWINFO __RPC_FAR *phlbwi);


void __RPC_STUB IHlinkBrowseContext_GetBrowseWindowInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetInitialHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [unique][in] */ LPCWSTR pwzFriendlyName);


void __RPC_STUB IHlinkBrowseContext_SetInitialHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_OnNavigateHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD grfHLNF,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [unique][in] */ LPCWSTR pwzFriendlyName,
    /* [out] */ ULONG __RPC_FAR *puHLID);


void __RPC_STUB IHlinkBrowseContext_OnNavigateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_UpdateHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ ULONG uHLID,
    /* [unique][in] */ IMoniker __RPC_FAR *pimkTarget,
    /* [unique][in] */ LPCWSTR pwzLocation,
    /* [unique][in] */ LPCWSTR pwzFriendlyName);


void __RPC_STUB IHlinkBrowseContext_UpdateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_EnumNavigationStack_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD dwReserved,
    /* [in] */ DWORD grfHLFNAMEF,
    /* [out] */ IEnumHLITEM __RPC_FAR *__RPC_FAR *ppienumhlitem);


void __RPC_STUB IHlinkBrowseContext_EnumNavigationStack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_QueryHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD grfHLQF,
    /* [in] */ ULONG uHLID);


void __RPC_STUB IHlinkBrowseContext_QueryHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ ULONG uHLID,
    /* [out] */ IHlink __RPC_FAR *__RPC_FAR *ppihl);


void __RPC_STUB IHlinkBrowseContext_GetHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetCurrentHlink_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ ULONG uHLID);


void __RPC_STUB IHlinkBrowseContext_SetCurrentHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Clone_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [unique][in] */ IUnknown __RPC_FAR *piunkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppiunkObj);


void __RPC_STUB IHlinkBrowseContext_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Close_Proxy( 
    IHlinkBrowseContext __RPC_FAR * This,
    /* [in] */ DWORD reserved);


void __RPC_STUB IHlinkBrowseContext_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHlinkBrowseContext_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0085
 * at Fri May 24 09:43:35 1996
 * using MIDL 2.00.0101
 ****************************************/
/* [local] */ 


#endif
                                                                              
#endif // !HLINK_H                                                            


extern RPC_IF_HANDLE __MIDL__intf_0085_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0085_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
