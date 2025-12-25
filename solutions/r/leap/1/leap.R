leap <- function(year) {
  t1 <- (year %% 4 == 0)
  t2 <- (year %% 100 != 0)
  t3 <- (year %% 400 == 0)

  (t1 & t2) | t3

}
