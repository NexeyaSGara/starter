/*----- PROTECTED REGION ID(Starter.h) ENABLED START -----*/
//=============================================================================
//
// file :        Starter.h
//
// description : Include for the Starter class.
//
// project :     Starter for Tango Administration.
//
// $Author$
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011,2012,2013,2014,2015
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Revision$
// $Date$
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef STARTER_H
#define STARTER_H


#include <tango.h>
#include <StarterUtil.h>
#include <sstream>


#define	TIME_BETWEEN_STARTUPS	500	//	Milli seconds
#define NOTIFY_DAEMON_SCRIPT	"notify_daemon"

//	Used onlyduring the Cpp Api bug fixing on
//	specAtt->get_max_x() method.
#define SERVER_TIMEOUT		30	//	Timeout Minimum at server startup


#ifdef _TG_WINDOWS_
#	define	LOG_HOME	"c:\\temp"
#else
#	define	LOG_HOME	"/var/tmp"
#endif

//	Structure to difine a new process to start
typedef struct {
	bool	could_start;
	char	*adminname;
	char	*servname;
	char	*instancename;
	char	*logfile;
}
NewProcess;


/*----- PROTECTED REGION END -----*/	//	Starter.h

/**
 *  Starter class description:
 *    This device server is able to control <b>Tango</b> components (database, device servers, clients...).
 *    It is able to start or stop and to report the status of these components.
 */

namespace Starter_ns
{
/*----- PROTECTED REGION ID(Starter::Additional Class Declarations) ENABLED START -----*/

		//		Additional Class Declarations
class StartProcessShared;

	/*----- PROTECTED REGION END -----*/	//	Starter::Additional Class Declarations

class Starter : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(Starter::Data Members) ENABLED START -----*/

	//		Add your own data members
public:
	/**
	 *	Start process thread Shared data
	 */
	StartProcessShared	*start_proc_data;
	/**
	 *	StarterUtil instance to be used everywhere.
	 */
	StarterUtil	*util;
	/**
	 *	Structures defining servers to be controlled
	 */
	vector<ControlledServer>		servers;
	/**
	 *	Exception must be or not thrown.
	 */
	Tango::DevBoolean	throwable;
	/**
	 *	Static string to be returned.
	 */
	string	returned_str;
	/**
	 *	Database device (as DeviceProxy) for not implemented API commands.
	 */
	Tango::DeviceProxy	*dbase;
	/**
	 *	Notify daemon State.
	 */
	Tango::DevState	notifyd_state;
	/**
	 *	Is server list modification fired from DB ds.
	 */
	Tango::DevShort	fireFromDbase;
	bool	do_update_from_db;

	Tango::DevString			dummyStringArray[1];
	Tango::DevVarStringArray	stringArrayRunning;
	Tango::DevVarStringArray	stringArrayStopped;
	Tango::DevVarStringArray	stringArrayServers;

	bool debug;

	/*----- PROTECTED REGION END -----*/	//	Starter::Data Members

//	Device property data members
public:
	//	AutoRestartDuration:	If this property is greater than 0, if a server has been running more than the specified value (in minutes), and has failed, it will be restart automaticly.
	Tango::DevLong	autoRestartDuration;
	//	InterStartupLevelWait:	Time to wait before two startup levels in seconds.
	Tango::DevLong	interStartupLevelWait;
	//	KeepLogFiles:	Number of log file kept.
	Tango::DevLong	keepLogFiles;
	//	LogFileHome:	The home directory to log servers traces.
	//  For Linux the default value is /var/tmp
	//  For Win32 it is c:\temp
	string	logFileHome;
	//	ServerStartupTimeout:	Timeout on device server startup in seconds.
	Tango::DevLong	serverStartupTimeout;
	//	StartDsPath:	Path to find executable files
	//  to start device servers
	vector<string>	startDsPath;
	//	StartServersAtStartup:	Skip starting servers at startup if false.
	Tango::DevBoolean	startServersAtStartup;
	//	UseEvents:	Use events if not null.
	Tango::DevShort	useEvents;
	//	WaitForDriverStartup:	The Starter will wait a bit before starting servers, to be sure than the drivers
	//  are started.This time is in seconds.
	Tango::DevShort	waitForDriverStartup;

//	Attribute data members
public:
	Tango::DevState	*attr_NotifdState_read;
	Tango::DevShort	*attr_HostState_read;
	Tango::DevString	*attr_RunningServers_read;
	Tango::DevString	*attr_StoppedServers_read;
	Tango::DevString	*attr_Servers_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Starter(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Starter(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	Starter(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~Starter() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : Starter::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute NotifdState related methods
 *	Description: return ON or FAULT if notify daemon is running or not.
 *
 *	Data type:	Tango::DevState
 *	Attr type:	Scalar
 */
	virtual void read_NotifdState(Tango::Attribute &attr);
	virtual bool is_NotifdState_allowed(Tango::AttReqType type);
/**
 *	Attribute HostState related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_HostState(Tango::Attribute &attr);
	virtual bool is_HostState_allowed(Tango::AttReqType type);
/**
 *	Attribute RunningServers related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 1024
 */
	virtual void read_RunningServers(Tango::Attribute &attr);
	virtual bool is_RunningServers_allowed(Tango::AttReqType type);
/**
 *	Attribute StoppedServers related methods
 *	Description: Return all the Stopped servers.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 1024
 */
	virtual void read_StoppedServers(Tango::Attribute &attr);
	virtual bool is_StoppedServers_allowed(Tango::AttReqType type);
/**
 *	Attribute Servers related methods
 *	Description: Return all registred servers for this host.\nServer names are followed by their states and controls
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 1024
 */
	virtual void read_Servers(Tango::Attribute &attr);
	virtual bool is_Servers_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : Starter::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command State related method
	 *	Description: This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
	 *
	 *	@returns State Code
	 */
	virtual Tango::DevState dev_state();
	/**
	 *	Command DevStart related method
	 *	Description: Start the specified server.
	 *
	 *	@param argin Server to be started.
	 */
	virtual void dev_start(Tango::DevString argin);
	virtual bool is_DevStart_allowed(const CORBA::Any &any);
	/**
	 *	Command DevStop related method
	 *	Description: Stop the specified server.
	 *
	 *	@param argin Servero be stopped.
	 */
	virtual void dev_stop(Tango::DevString argin);
	virtual bool is_DevStop_allowed(const CORBA::Any &any);
	/**
	 *	Command DevStartAll related method
	 *	Description: Start all device servers controled on the host for the argin level.
	 *
	 *	@param argin Startup level.
	 */
	virtual void dev_start_all(Tango::DevShort argin);
	virtual bool is_DevStartAll_allowed(const CORBA::Any &any);
	/**
	 *	Command DevStopAll related method
	 *	Description: Stop all device servers controled on the host for the argin level.
	 *
	 *	@param argin Startup Level.
	 */
	virtual void dev_stop_all(Tango::DevShort argin);
	virtual bool is_DevStopAll_allowed(const CORBA::Any &any);
	/**
	 *	Command DevGetRunningServers related method
	 *	Description: Control the running process from property list.
	 *               And return the list of the processes which are really running.
	 *
	 *	@param argin True for all servers. False for controled servers only.
	 *	@returns List of the processes which are running.
	 */
	virtual Tango::DevVarStringArray *dev_get_running_servers(Tango::DevBoolean argin);
	virtual bool is_DevGetRunningServers_allowed(const CORBA::Any &any);
	/**
	 *	Command DevGetStopServers related method
	 *	Description: Control the running process from property list.
	 *               And return the list of the processes which are not running.
	 *
	 *	@param argin True for all servers. False for controled servers only.
	 *	@returns List of the processes which are not running.
	 */
	virtual Tango::DevVarStringArray *dev_get_stop_servers(Tango::DevBoolean argin);
	virtual bool is_DevGetStopServers_allowed(const CORBA::Any &any);
	/**
	 *	Command DevReadLog related method
	 *	Description: At server startup, its standard error is redirected to a log file.
	 *               This command will read this file and return the read string from the file.
	 *
	 *	@param argin server name and domain (e.g. Starter/corvus)
	 *               If argin ==``Starter``     -> return Starter logg file content.
	 *               If argin ==``Statistics``  -> return Starter statistics file content.
	 *	@returns String found in log file.
	 */
	virtual Tango::ConstDevString dev_read_log(Tango::DevString argin);
	virtual bool is_DevReadLog_allowed(const CORBA::Any &any);
	/**
	 *	Command HardKillServer related method
	 *	Description: Hard kill a server (kill -9)
	 *
	 *	@param argin Server name
	 */
	virtual void hard_kill_server(Tango::DevString argin);
	virtual bool is_HardKillServer_allowed(const CORBA::Any &any);
	/**
	 *	Command NotifyDaemonState related method
	 *	Description: Returns the Notify Daemon state.
	 *
	 *	@returns Tango::ON if Notify daemon is running else Tango::FAULT.
	 */
	virtual Tango::DevState notify_daemon_state();
	virtual bool is_NotifyDaemonState_allowed(const CORBA::Any &any);
	/**
	 *	Command ResetStatistics related method
	 *	Description: Reset statistics file.
	 *
	 */
	virtual void reset_statistics();
	virtual bool is_ResetStatistics_allowed(const CORBA::Any &any);
	/**
	 *	Command UpdateServersInfo related method
	 *	Description: Indicate to the device server than the information about servers to be controlled has been modified.
	 *               The device server must read the database to update the servers info list.
	 *               If the default case, this command is sent by Database server itself.
	 *
	 */
	virtual void update_servers_info();
	virtual bool is_UpdateServersInfo_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : Starter::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(Starter::Additional Method prototypes) ENABLED START -----*/

	//	Additional Method prototypes
protected :
/**
 * @name private methods prototypes
 */
//@{
/**
 *	Allocate and fill the servers controlled object
 */
void build_server_ctrl_object(void);
/**
 *	Return how many servers to start for specified level.
 */
int	nb_servers_to_start(int level);
/**
 *	Check if a process could be started (file exists, is not running, ...)
 */
NewProcess *processCouldStart(char *);
/**
 *	Start a thread to start processes
 */
void startProcesses(vector<NewProcess *>, int level);

/**
 *	check if instance and host name are coherent
 */
void check_host();
/**
 *	check if log dir already exists (else create it
 */
void check_log_dir();

void manage_changing_state(ControlledServer *server, Tango::DevState previous_state);
//@}

	/*----- PROTECTED REGION END -----*/	//	Starter::Additional Method prototypes
};

/*----- PROTECTED REGION ID(Starter::Additional Classes Definitions) ENABLED START -----*/




	//	Additional Classes definitions
//=========================================================
/**
 *	Shared data between DS and StartProcess thread.
 */
//=========================================================
class StartProcessShared: public Tango::TangoMonitor
{
private:
	/**
	 *	Manage levels thread
	 *	To be sure that (level) threads are not concurrent
	 */
	vector<int>	start_process_thread_levels;
	/**
	 *	Starter is MOVING (starting servers) when > 0;
	 */
	int	starting_processes;

public:
	StartProcessShared() {starting_processes=0;};

	void push_back_level(int level);
	int  get_current_level();
	int  get_starting_processes();
	void remove_level(int level);
	bool level_is_still_active(int level);

};


#ifdef _TG_WINDOWS_
class StartWinThread: public omni_thread
{
	NewProcess	*process;
	Starter		*starter;
public:
	StartWinThread(NewProcess* proc, Starter *st)
		{ process = proc; starter=st;};

	// Set the path between cotes for windows.
	string get_server_name_with_cotes(string servname);

	void run(void *);
	//void start() {start_undetached();}
};
#endif

//=========================================================
/**
 *	Create a thread to fork a sub-process (new device server)
 */
//=========================================================
class StartProcessThread: public omni_thread
{
	vector<NewProcess *>	processes;
	Starter					*starter;
	int						thread_level;
public:
/**
 *	Initialize the sub process parameters (name, domain, log_file).
 */
	StartProcessThread(vector<NewProcess *> v_np, int level, Starter *st);
/**
 * Execute the fork of the sub process in a thread.
 */
	void run(void *);
	//void start() {start_undetached();}
/**
 *	Start one process
 */
 	void start_process(NewProcess *);
};

	/*----- PROTECTED REGION END -----*/	//	Starter::Additional Classes Definitions

}	//	End of namespace

#endif   //	Starter_H
