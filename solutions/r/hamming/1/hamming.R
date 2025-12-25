# This is a stub function to take two strings
# and calculate the hamming distance
hamming <- function(strand1, strand2) {
  hamming <- 0
  vec1 <- strsplit(strand1, '')[[1]]
  vec2 <- strsplit(strand2, '')[[1]]
  len1 <- length(vec1)
  len2 <- length(vec2)
  if (len1 != len2) {stop(simpleError('length of two strands not the same!'))}
  if (len1 == 0) {return(0)}
  for (i in 1:len1){
    if (vec1[[i]] != vec2[[i]]) {hamming <- hamming + 1}
  }
hamming

}
