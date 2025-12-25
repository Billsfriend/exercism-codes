reverse <- function(text) {
  if (nchar(text) == 0) {return('')}  
  splited <- strsplit(text, split = '')
  paste(rev(splited[[1]]), collapse = '')
  
}
