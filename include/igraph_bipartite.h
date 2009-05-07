/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_BIPARTITE_H
#define IGRAPH_BIPARTITE_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_constants.h"
#include "igraph_types.h"
#include "igraph_datatype.h"

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Bipartite networks                                 */
/* -------------------------------------------------- */

int igraph_full_bipartite(igraph_t *graph, 
			  igraph_vector_bool_t *types,
			  igraph_integer_t n1, igraph_integer_t n2,
			  igraph_bool_t directed, 
			  igraph_neimode_t mode);

int igraph_create_bipartite(igraph_t *g, const igraph_vector_bool_t *types,
			    const igraph_vector_t *edges, 
			    igraph_bool_t directed);

int igraph_bipartite_projection_size(const igraph_t *graph,
				     const igraph_vector_bool_t *types,
				     igraph_integer_t *vcount1,
				     igraph_integer_t *ecount1,
				     igraph_integer_t *vcount2,
				     igraph_integer_t *ecount2);

int igraph_bipartite_projection(const igraph_t *graph, 
				const igraph_vector_bool_t *types,
				igraph_t *proj1,
				igraph_t *proj2,
				igraph_integer_t probe1);

int igraph_incidence(igraph_t *graph, igraph_vector_bool_t *types,
		     const igraph_matrix_t *incidence,  igraph_bool_t directed,
		     igraph_neimode_t mode, igraph_bool_t multiple);

int igraph_get_incidence(const igraph_t *graph,
			 const igraph_vector_bool_t *types,
			 igraph_matrix_t *res,
			 igraph_vector_t *row_ids,
			 igraph_vector_t *col_ids);

int igraph_is_bipartite(const igraph_t *graph,
			igraph_bool_t *res,
			igraph_vector_bool_t *type);


__END_DECLS

#endif