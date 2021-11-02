/* Copyright (c) 1995-1996, Microsoft Corporation, all rights reserved
**
** msconf.h
**
** Microsoft ActiveX Conferencing SDK
** Version 1.0.  Beta 1
** Unpublished work.
**
** Public header for external API clients
*/

#ifndef _MSCONF_H_
#define _MSCONF_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CONF_VERSION            0x0001


// String constants
#define CONF_MAX_USERNAME        64
#define CONF_MAX_CONFERENCENAME 128


/* Error constants
*/

#define CONFERR_BASE                   0x09000L

#define CONFERR_INVALID_PARAMETER      (CONFERR_BASE + 1)
#define CONFERR_INVALID_HCONF          (CONFERR_BASE + 2)
#define CONFERR_INVALID_BUFFER         (CONFERR_BASE + 3)
#define CONFERR_BUFFER_TOO_SMALL       (CONFERR_BASE + 4)
#define CONFERR_ENUM_COMPLETE          (CONFERR_BASE + 5)

// File Transfer error codes
#define CONFERR_FILE_TRANSFER          (CONFERR_BASE + 10)
#define CONFERR_FILE_SEND_ABORT        (CONFERR_BASE + 11)
#define CONFERR_FILE_RECEIVE_ABORT     (CONFERR_BASE + 12)

// Overloaded Error Codes
#define CONFERR_OUT_OF_MEMORY          ERROR_NOT_ENOUGH_MEMORY
#define CONFERR_FILE_NOT_FOUND         ERROR_FILE_NOT_FOUND
#define CONFERR_PATH_NOT_FOUND         ERROR_PATH_NOT_FOUND
#define CONFERR_ACCESS_DENIED          ERROR_ACCESS_DENIED
#define CONFERR_RECEIVE_DIR            ERROR_DISK_FULL

#define CONFERR_SUCCESS                0

typedef DWORD CONFERR;


/* Main conferencing identifier
*/
typedef HANDLE HCONF;


/* Notification Callback
*/
typedef LONG (CALLBACK* CONFNOTIFYPROC)(HCONF, DWORD, DWORD, LPVOID, LPVOID);



/* Describes a conference connection address
*/
typedef struct tagConfAddr {
	DWORD dwSize;                    // size of this structure, in bytes
	DWORD dwAddrType;                // type of address that follows
	union {
		DWORD dwIp;              // IP Address (a.b.c.d)
		PTSTR psz;               // pointer to a null terminated string
		};
} CONFADDR;
typedef CONFADDR * LPCONFADDR;

// CONFADDR dwAddrType values
#define CONF_ADDR_UNKNOWN      0x0000 // address type is not known
#define CONF_ADDR_IP           0x0001 // use dwIp as a binary IP address
#define CONF_ADDR_MACHINENAME  0x0002 // use sz as a local machine name
#define CONF_ADDR_PSTN         0x0003 // use sz as a TAPI canonical telephone number


/* Describes a destination within a conference
*/
typedef struct tagConfDest {
	DWORD dwSize;                   // size of this structure, in bytes
	DWORD dwFlags;                  // Destination flags (CONF_DF_xxx)
	DWORD dwUserId;                 // unique user identifier
	GUID  guid;                     // globally unique application identifier
} CONFDEST;
typedef CONFDEST * LPCONFDEST;

// CONFDEST dwFlags
#define CONF_DF_BROADCAST      0x0100 // data was broadcast to everyone
#define CONF_DF_PRIVATE        0x0200 // data was private


/* Describes the conference settings
*/
typedef struct tagConfInfo {
	DWORD dwSize;                   // size of this structure, in bytes
	DWORD dwFlags;                  // Conference options (CONF_IF_xxx)
	DWORD dwMediaType;              // Media Type (CONF_MT_xxx)
	DWORD dwGCCID;
	HCONF hConf;                    // Conference Handle
	DWORD cUsers;                   // number of participants in the conference
	CONFNOTIFYPROC pfnNotifyProc;   // Notification call-back 
	TCHAR szConferenceName[CONF_MAX_CONFERENCENAME];
} CONFINFO;
typedef CONFINFO * LPCONFINFO;

// CONFINFO dwMediaType
#define CONF_MT_DATA      0x0001
#define CONF_MT_AUDIO     0x0002
#define CONF_MT_VIDEO     0x0004
#define CONF_MT_ALL       0xFFFF


/* Describes a user within a conference
*/
typedef struct tagConfUserInfo {
	DWORD dwSize;                   // size of this structure, in bytes
	DWORD dwUserId;                 // GCC NodeId
	DWORD dwReserved;
	TCHAR szUserName[CONF_MAX_USERNAME];
} CONFUSERINFO;
typedef CONFUSERINFO * LPCONFUSERINFO;


/* Describes the default receive directory for transferred files
*/
typedef struct tagConfRecDir {
	DWORD dwSize;                   // size of this structure, in bytes
	TCHAR szRecDir[MAX_PATH];
} CONFRECDIR;
typedef CONFRECDIR * LPCONFRECDIR;


/* Describes the notification callback
*/
typedef struct tagConfNotify {
	DWORD dwSize;                   // size of this structure, in bytes
	DWORD dwFlags;                  // reserved for future use
	CONFNOTIFYPROC pfnNotifyProc;   // the notification callback routine
	GUID  guid;                     // globally unique application identifier
} CONFNOTIFY;
typedef CONFNOTIFY * LPCONFNOTIFY;


/* Describes an application to be launched when receiving files or data
*/
typedef struct tagConfGuid {
	DWORD   dwSize;                 // size of this structure, in bytes
	GUID    guid;                   // globally unique application identifier
	LPCTSTR pszApplication;         // application to run
	LPCTSTR pszCommandLine;         // command line paramters
	LPCTSTR pszDirectory;           // working directory
} CONFGUID;
typedef CONFGUID * LPCONFGUID;


/* Describes a file in the process of being transferred
*/
typedef struct tagConfFileInfo {
	DWORD dwSize;                   // size of this structure, in bytes
	DWORD dwFileId;                 // unique file identifier
	DWORD dwFileSize;               // size of the file in bytes
	DWORD dwBytesTransferred;       // number of bytes currently transferred
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	TCHAR szFileNameSrc[MAX_PATH];  // original file name
	TCHAR szFileNameDest[MAX_PATH]; // destination file name
} CONFFILEINFO;
typedef CONFFILEINFO * LPCONFFILEINFO;


/* ConferenceGetInfo dwCode
*/
#define CONF_GET_CONF                0x0001 // LPCONFINFO
#define CONF_ENUM_CONF               0x0002 // LPCONFINFO
#define CONF_GET_USER                0x0011 // LPUSERINFO
#define CONF_ENUM_USER               0x0012 // LPUSERINFO
#define CONF_GET_RECDIR              0x0020 // LPCONFRECDIR
#define CONF_GET_FILEINFO            0x0021 // LPFILEINFO


/* ConferenceSetInfo dwCode
*/
#define CONF_SET_NOTIFY              0x1001 // LPCONFNOTIFY
#define CONF_REMOVE_NOTIFY           0x1002 // LPCONFNOTIFY
#define CONF_SET_RECDIR              0x1020 // LPCONFRECDIR
#define CONF_SET_GUID                0x1041 // LPCONFGUID


/* ConferenceSendFile dwFlags
*/
#define CONF_SF_NOWAIT               0x0001
#define CONF_SF_NOUI                 0x0002
#define CONF_SF_NOCOMPRESS           0x0004


/* ShareWindow dwFlags
*/
#define CONF_SW_SHARE                0x0001
#define CONF_SW_UNSHARE              0x0002


/* Notification Codes
*/
#define CONFN_CONFERENCE_INIT        0x0001 // 0,        LPCONFADDR, LPCONFINFO
#define CONFN_CONFERENCE_START       0x0002 // 0,        LPCONFADDR, LPCONFINFO
#define CONFN_CONFERENCE_STOP        0x0003 // 0,        LPCONFADDR, LPCONFINFO
#define CONFN_CONFERENCE_ERROR       0x0004 // 0,        LPCONFADDR, LPCONFINFO
#define CONFN_USER_ADDED             0x0011 // dwUserId, LPCONFADDR, LPCONFINFO
#define CONFN_USER_REMOVED           0x0012 // dwUserId, LPCONFADDR, LPCONFINFO
#define CONFN_PEER_ADDED             0x0021 // dwUserId, LPCONFDEST, 0
#define CONFN_PEER_REMOVED           0x0022 // dwUserId, LPCONFDEST, 0
#define CONFN_WINDOW_SHARED          0x0041 // HWND,     0         , 0
#define CONFN_WINDOW_UNSHARED        0x0042 // HWND,     0         , 0
#define CONFN_DATA_SENT              0x0101 // DWORD,    LPCONFDEST, LPVOID
#define CONFN_DATA_RECEIVED          0x0102 // DWORD,    LPCONFDEST, LPVOID
#define CONFN_FILESEND_START         0x0111 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILESEND_PROGRESS      0x0112 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILESEND_COMPLETE      0x0113 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILESEND_ERROR         0x0114 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILERECEIVE_START      0x0121 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILERECEIVE_PROGRESS   0x0122 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILERECEIVE_COMPLETE   0x0123 // dwFileId, LPCONFDEST, LPCONFFILEINFO
#define CONFN_FILERECEIVE_ERROR      0x0124 // dwFileId, LPCONFDEST, LPCONFFILEINFO


/* Conferencing functions found in MSCONF.DLL
*/

DWORD WINAPI ConferenceConnect(HCONF * phConf, LPCONFADDR lpConfAddr, LPCONFINFO lpConfInfo);
DWORD WINAPI ConferenceDisconnect(HCONF hConf);
DWORD WINAPI ConferenceGetInfo(HCONF hConf, DWORD dwCode, LPVOID lpv);
DWORD WINAPI ConferenceSetInfo(HCONF hConf, DWORD dwCode, LPVOID lpv);
DWORD WINAPI ConferenceLaunchRemote(HCONF hConf, LPCONFDEST lpConfDest, DWORD dwReserved);
DWORD WINAPI ConferenceSendData(HCONF hConf, LPCONFDEST lpConfDest, LPVOID lpv, DWORD cb, DWORD dwFlags);
DWORD WINAPI ConferenceSendFile(HCONF hConf, LPCONFDEST lpConfDest, LPCTSTR szFileName, DWORD dwFlags);
DWORD WINAPI ConferenceShareWindow(HWND hwnd, HCONF hConf, DWORD dwFlags);
BOOL  WINAPI ConferenceIsWindowShared(HWND hwnd, HCONF * phConf);

#ifdef __cplusplus
}
#endif

#endif // _MSCONF_H_

