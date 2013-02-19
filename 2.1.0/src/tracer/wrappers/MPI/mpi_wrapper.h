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

#ifndef MPI_WRAPPER_DEFINED
#define MPI_WRAPPER_DEFINED

#if !defined(MPI_SUPPORT)
# error "This should not be included"
#endif

# include <config.h>

#ifdef HAVE_MPI_H
# include <mpi.h>
#endif
#include "mpif.h"
#include "defines.h"

#include "wrapper.h"

void gettopology (void);
void configure_MPI_vars (void);
unsigned long long CalculateNumOpsForPeriod (unsigned long long wannaPeriod, unsigned long long NumOfGlobals, unsigned long long runnedPeriod);
void CheckControlFile (void);
void CheckGlobalOpsTracingIntervals (void);
void CtoF77 (mptrace_set_mlp_rank) (int *rank, int *size);
void remove_file_list (void);
extern int mpit_gathering_enabled;

void OMPItrace_network_counters_Wrapper (void);
void OMPItrace_network_routes_Wrapper (int mpi_rank);
void OMPItrace_tracing_tasks_Wrapper (int from, int to);

/* Fortran Wrappers */

#if defined(FORTRAN_SYMBOLS)

#if (defined(COMBINED_SYMBOLS) && defined(MPI_C_CONTAINS_FORTRAN_MPI_INIT) || \
     !defined(COMBINED_SYMBOLS))
void PMPI_Init_Wrapper (MPI_Fint *ierror);
#endif

void PMPI_Init_thread_Wrapper (MPI_Fint *required, MPI_Fint *provided, MPI_Fint *ierror);

void PMPI_Finalize_Wrapper (MPI_Fint *ierror);

void PMPI_BSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_SSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_RSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Send_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_IBSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_ISend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_ISSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_IRSend_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Recv_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, 
   MPI_Fint *ierror);

void PMPI_IRecv_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Reduce_Wrapper (void *sendbuf, void *recvbuf, MPI_Fint *count,
	MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *root, MPI_Fint *comm,
	MPI_Fint *ierror);

void PMPI_AllReduce_Wrapper (void *sendbuf, void *recvbuf, MPI_Fint *count,
	MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Probe_Wrapper (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
	MPI_Fint *status, MPI_Fint *ierror);

void PMPI_IProbe_Wrapper (MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm,
	MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror);

void PMPI_Barrier_Wrapper (MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Cancel_Wrapper (MPI_Fint *request, MPI_Fint *ierror);

void PMPI_Test_Wrapper (MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status,
	MPI_Fint *ierror);

void PMPI_Wait_Wrapper (MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierror);

void PMPI_WaitAll_Wrapper (MPI_Fint * count, MPI_Fint array_of_requests[],
	MPI_Fint array_of_statuses[][SIZEOF_MPI_STATUS], MPI_Fint * ierror);

void PMPI_WaitAny_Wrapper (MPI_Fint *count, MPI_Fint array_of_requests[],
	MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierror);

void PMPI_WaitSome_Wrapper (MPI_Fint *incount, MPI_Fint array_of_requests[],
	MPI_Fint *outcount, MPI_Fint array_of_indices[],
	MPI_Fint array_of_statuses[][SIZEOF_MPI_STATUS], MPI_Fint *ierror);

void PMPI_BCast_Wrapper (void *buffer, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_AllToAll_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype,
	MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_AllToAllV_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sdispls, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount,
   MPI_Fint *rdispls, MPI_Fint *recvtype,	MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Allgather_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype,
	MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Allgatherv_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *displs,
	MPI_Fint *recvtype, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Gather_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype,
	MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_GatherV_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *displs,
	MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Scatter_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype,
	MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_ScatterV_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *displs, MPI_Fint *sendtype, void *recvbuf, MPI_Fint *recvcount,
	MPI_Fint *recvtype, MPI_Fint *root, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Comm_Rank_Wrapper (MPI_Fint *comm, MPI_Fint *rank, MPI_Fint *ierror);

void PMPI_Comm_Size_Wrapper (MPI_Fint *comm, MPI_Fint *size, MPI_Fint *ierror);

void PMPI_Comm_Create_Wrapper (MPI_Fint *comm, MPI_Fint *group,
	MPI_Fint *newcomm, MPI_Fint *ierror);

void PMPI_Comm_Dup_Wrapper (MPI_Fint *comm, MPI_Fint *newcomm,
	MPI_Fint *ierror);

void PMPI_Comm_Split_Wrapper (MPI_Fint *comm, MPI_Fint *color, MPI_Fint *key,
	MPI_Fint *newcomm, MPI_Fint *ierror);

void PMPI_Reduce_Scatter_Wrapper (void *sendbuf, void *recvbuf,
	MPI_Fint *recvcounts, MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm,
	MPI_Fint *ierror);

void PMPI_Scan_Wrapper (void *sendbuf, void *recvbuf, MPI_Fint *count,
	MPI_Fint *datatype, MPI_Fint *op, MPI_Fint *comm, MPI_Fint *ierror);

void PMPI_Start_Wrapper (MPI_Fint *request, MPI_Fint *ierror);

void PMPI_Startall_Wrapper (MPI_Fint *count, MPI_Fint array_of_requests[],
	MPI_Fint *ierror);

void PMPI_Request_free_Wrapper (MPI_Fint *request, MPI_Fint *ierror);

void PMPI_Recv_init_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Send_init_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Bsend_init_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Rsend_init_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Ssend_init_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *datatype,
	MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request,
	MPI_Fint *ierror);

void PMPI_Cart_sub_Wrapper (MPI_Fint *comm, MPI_Fint *remain_dims,
	MPI_Fint *comm_new, MPI_Fint *ierror);

void PMPI_Cart_create_Wrapper (MPI_Fint *comm_old, MPI_Fint *ndims,
	MPI_Fint *dims, MPI_Fint *periods, MPI_Fint *reorder, MPI_Fint *comm_cart,
	MPI_Fint *ierror);

void MPI_Sendrecv_Fortran_Wrapper (void *sendbuf, MPI_Fint *sendcount,
	MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf,
	MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag,
	MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr);

void MPI_Sendrecv_replace_Fortran_Wrapper (void *buf, MPI_Fint *count, MPI_Fint *type,
	MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag,
	MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierr);

#if defined(MPI_SUPPORTS_MPI_IO)

void PMPI_File_open_Fortran_Wrapper (MPI_Fint *comm, char *filename,
	MPI_Fint *amode, MPI_Fint *info, MPI_File *fh, MPI_Fint *len);

void PMPI_File_close_Fortran_Wrapper (MPI_File *fh, MPI_Fint *ierror);

void PMPI_File_read_Fortran_Wrapper (MPI_File *fh, void *buf, MPI_Fint *count,
	MPI_Fint *datatype, MPI_Status *status, MPI_Fint *ierror);

void PMPI_File_read_all_Fortran_Wrapper (MPI_File *fh, void *buf,
	MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status, MPI_Fint *ierror);

void PMPI_File_write_Fortran_Wrapper (MPI_File *fh, void *buf, MPI_Fint *count,
	MPI_Fint *datatype, MPI_Status *status, MPI_Fint *ierror);

void PMPI_File_write_all_Fortran_Wrapper (MPI_File *fh, void *buf,
	MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status, MPI_Fint *ierror);

void PMPI_File_read_at_Fortran_Wrapper (MPI_File *fh, MPI_Offset *offset,
	void* buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status,
	MPI_Fint *ierror);

void PMPI_File_read_at_all_Fortran_Wrapper (MPI_File *fh, MPI_Offset *offset,
	void* buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status,
   MPI_Fint *ierror);

void PMPI_File_write_at_Fortran_Wrapper (MPI_File *fh, MPI_Offset *offset,
	void* buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status,
	MPI_Fint *ierror);

void PMPI_File_write_at_all_Fortran_Wrapper (MPI_File *fh, MPI_Offset *offset,
	void* buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Status *status,
	MPI_Fint *ierror);

#endif /* MPI_SUPPORTS_MPI_IO */

#endif /* defined(FORTRAN_SYMBOLS) */

/* C Wrappers */

#if defined(C_SYMBOLS)

int MPI_Init_C_Wrapper (int *argc, char ***argv);

int MPI_Init_thread_C_Wrapper (int *argc, char ***argv, int required, int *provided);

int MPI_Finalize_C_Wrapper (void);

int MPI_Bsend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm);

int MPI_Ssend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm);

int MPI_Rsend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm);

int MPI_Send_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm);

int MPI_Ibsend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Isend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Issend_C_Wrapper (void *buf, int count, MPI_Datatype datatype, int dest,
  int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Irsend_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Recv_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int source, int tag, MPI_Comm comm, MPI_Status *status);

int MPI_Irecv_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int source, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Reduce_C_Wrapper (void *sendbuf, void *recvbuf, int count,
  MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);

int MPI_Allreduce_C_Wrapper (void *sendbuf, void *recvbuf, int count,
  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Probe_C_Wrapper (int source, int tag, MPI_Comm comm, MPI_Status *status);

int MPI_Iprobe_C_Wrapper (int source, int tag, MPI_Comm comm, int *flag,
  MPI_Status *status);

int MPI_Iprobe_C_Wrapper (int source, int tag, MPI_Comm comm, int *flag,
  MPI_Status *status);

int MPI_Barrier_C_Wrapper (MPI_Comm comm);

int MPI_Cancel_C_Wrapper (MPI_Request * request);

int MPI_Test_C_Wrapper (MPI_Request * request, int *flag, MPI_Status *status);

int MPI_Wait_C_Wrapper (MPI_Request * request, MPI_Status *status);

int MPI_Waitall_C_Wrapper (int count, MPI_Request* requests, MPI_Status *statuses);

int MPI_Waitany_C_Wrapper (int count, MPI_Request* requests, int *index,
  MPI_Status *status);

int MPI_Waitsome_C_Wrapper (int incount, MPI_Request* requests, int *outcount,
  int *indices, MPI_Status *statuses);

int MPI_BCast_C_Wrapper (void *buffer, int count, MPI_Datatype datatype,
  int root, MPI_Comm comm);

int MPI_Alltoall_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Alltoallv_C_Wrapper (void *sendbuf, int *sendcounts, int *sdispls,
  MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *rdispls, MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Allgather_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Allgatherv_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Gather_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_Gatherv_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_Scatter_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_Scatterv_C_Wrapper (void *sendbuf, int *sendcounts, int *displs,
  MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_Comm_rank_C_Wrapper (MPI_Comm comm, int *rank);

int MPI_Comm_size_C_Wrapper (MPI_Comm comm, int *size);

int MPI_Comm_create_C_Wrapper (MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);

int MPI_Comm_dup_C_Wrapper (MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Comm_split_C_Wrapper (MPI_Comm comm, int color, int key, MPI_Comm *newcomm);

int MPI_Reduce_Scatter_C_Wrapper (void *sendbuf, void *recvbuf, int *recvcounts,
  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Scan_C_Wrapper (void *sendbuf, void *recvbuf, int count,
  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Cart_create_C_Wrapper (MPI_Comm comm_old, int ndims, int *dims,
  int *periods, int reorder, MPI_Comm *comm_cart);

int MPI_Cart_sub_C_Wrapper (MPI_Comm comm, int *remain_dims, MPI_Comm *comm_new);

int MPI_Start_C_Wrapper (MPI_Request* request);

int MPI_Startall_C_Wrapper (int count, MPI_Request* requests);

int MPI_Request_free_C_Wrapper (MPI_Request * request);

int MPI_Recv_init_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int source, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Send_init_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Bsend_init_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Rsend_init_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Ssend_init_C_Wrapper (void *buf, int count, MPI_Datatype datatype,
  int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Sendrecv_C_Wrapper (void *sendbuf, int sendcount, MPI_Datatype sendtype,
  int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype,
  int source, int recvtag, MPI_Comm comm, MPI_Status * status);

int MPI_Sendrecv_replace_C_Wrapper (void *buf, int count, MPI_Datatype type,
  int dest, int sendtag, int source, int recvtag, MPI_Comm comm,
  MPI_Status * status);

#if defined(MPI_SUPPORTS_MPI_IO)

int MPI_File_open_C_Wrapper (MPI_Comm comm, char *filename, int amode,
  MPI_Info info, MPI_File *fh);

int MPI_File_close_C_Wrapper (MPI_File *fh);

int MPI_File_read_C_Wrapper (MPI_File fh, void *buf, int count,
  MPI_Datatype datatype, MPI_Status *status);

int MPI_File_read_all_C_Wrapper (MPI_File fh, void *buf, int count,
  MPI_Datatype datatype, MPI_Status *status);

int MPI_File_write_C_Wrapper (MPI_File fh, void *buf, int count,
	MPI_Datatype datatype, MPI_Status *status);

int MPI_File_write_all_C_Wrapper (MPI_File fh, void *buf, int count,
  MPI_Datatype datatype, MPI_Status *status);

int MPI_File_read_at_C_Wrapper (MPI_File fh, MPI_Offset offset, void *buf, 
  int count, MPI_Datatype datatype, MPI_Status *status);

int MPI_File_read_at_all_C_Wrapper (MPI_File fh, MPI_Offset offset, void *buf,
  int count, MPI_Datatype datatype, MPI_Status *status);

int MPI_File_write_at_C_Wrapper (MPI_File fh, MPI_Offset offset, void *buf,
  int count, MPI_Datatype datatype, MPI_Status *status);

int MPI_File_write_at_all_C_Wrapper (MPI_File fh, MPI_Offset offset, void *buf,
  int count, MPI_Datatype datatype, MPI_Status *status);

#endif /* MPI_SUPPORTS_MPI_IO */

int MPI_Type_size (MPI_Datatype datatype, int *size);

#endif /* defined(C_SYMBOLS) */

#endif /* MPI_WRAPPER_DEFINED */

