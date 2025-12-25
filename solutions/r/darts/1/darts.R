score <- function(x, y) {
  radius2 = x ^ 2 + y ^ 2
  if (radius2 <= 1) return(10)
  if (radius2 <= 25) return(5)
  if (radius2 <= 100) return(1)
  else return(0)
}
