# this is a stub function that takes a natural_number
# and should return the difference-of-squares as described
# in the README.md
difference_of_squares <- function(natural_number) {
  sqr.of.sum = (sum(0:natural_number))^2
  sum.of.sqr = sum((0:natural_number)^2)
  sqr.of.sum - sum.of.sqr
}
