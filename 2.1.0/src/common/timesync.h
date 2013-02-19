/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                  MPItrace                                 *
 *              Instrumentation package for parallel applications            *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- *\
 | @file: $HeadURL$
 | @last_commit: $Date$
 | @version:     $Revision$
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef __TIMESYNC_H__
#define __TIMESYNC_H__

#include "types.h"

typedef struct
{
   int init;
   UINT64 init_time;
   UINT64 sync_time;
   int node_id;
} SyncInfo_t;

enum
{
   TS_NODE,
   TS_TASK,
   TS_DEFAULT,
   TS_NOSYNC
};

#ifdef __cplusplus
extern "C" {
#endif
int TimeSync_Initialize (int num_tasks);
int TimeSync_SetInitialTime (int task, UINT64 init_time, UINT64 sync_time, char *node);
int TimeSync_CalculateLatencies (int sync_strategy);
UINT64 TimeSync (int task, UINT64 time);
UINT64 TimeDesync (int task, UINT64 time);
#ifdef __cplusplus
}
#endif

#define TIMESYNC(task, time) TimeSync(task, time)

#define TIMEDESYNC(task, time) TimeDesync(task, time)

#endif /* __TIMESYNC_H__ */
