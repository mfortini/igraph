\name{modularity}
\alias{modularity}
\alias{modularity.igraph}
\concept{Modularity}
\title{Modularity of a community structure of a graph}
\description{This function calculates how modular is a given division of a
  graph into subgraphs.
}
\usage{
\method{modularity}{igraph}(x, membership, weights = NULL, \dots)
}
\arguments{
  \item{x}{The input graph.}
  \item{membership}{Numeric vector, for each vertex it gives its
    community. The communities are numbered from one.
  }
  \item{weights}{If not \code{NULL} then a numeric vector giving edge
    weights.}
  \item{\dots}{Additional arguments, none currently.}
}
\details{
  The modularity of a graph with respect to some division (or vertex
  types) measures how good the division is, or how separated are the 
  different vertex types from each other. It defined as 
  \deqn{Q=\frac{1}{2m} \sum_{i,j} A_{ij}-\frac{k_ik_j}{2m}\delta(c_i,c_j),}{Q=1/(2m) * sum(Aij-ki*kj/(2m)delta(ci,cj),i,j),}
  here \eqn{m} is the number of edges, \eqn{A_{ij}}{Aij} is the element
  of the \eqn{A} adjacency matrix 
  in row \eqn{i} and column \eqn{j}, \eqn{k_i}{ki} is the degree of \eqn{i},
  \eqn{k_j}{kj} is the degree of \eqn{j}, \eqn{c_i}{ci} is the type (or
  component) of \eqn{i}, \eqn{c_j}{cj} that of \eqn{j}, the sum goes
  over all \eqn{i} and \eqn{j} pairs of vertices, and
  \eqn{\delta(x,y)}{delta(x,y)} is 1 if \eqn{x=y} and 0 otherwise.

  If edge weights are given, then these are considered as the element of
  the \eqn{A} adjacency matrix, and \eqn{k_i}{ki} is the sum of weights
  of adjacent edges for vertex \eqn{i}.
}
\value{
  A numeric scalar, the modularity score of the given configuration.
}
\references{
  MEJ Newman and M Girvan: Finding and evaluating community
  structure in networks. Physical Review E 69 026113, 2004.
}
\author{Gabor Csardi \email{csardi.gabor@gmail.com}}
\seealso{
  \code{\link{walktrap.community}},
  \code{\link{edge.betweenness.community}},
  \code{\link{fastgreedy.community}},
  \code{\link{spinglass.community}} for various community detection
  methods.
}
\examples{
g <- graph.full(5) \%du\% graph.full(5) \%du\% graph.full(5)
g <- add.edges(g, c(1,6, 1,11, 6, 11))
wtc <- walktrap.community(g)
modularity(wtc)
modularity(g, membership(wtc))
}
\keyword{graphs}
