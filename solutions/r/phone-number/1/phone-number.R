parse_phone_number <- function(number_string) {
  res <- gsub(x = number_string, pattern = '[^0-9]', replacement = '')
  
  if (nchar(res) == 11 & substr(res, 1, 1) == '1') {
    res <- sub(x = res, pattern = '^1', replacement = '')
  }
  
  if (nchar(res) == 10 & grepl(x = substr(res, 1, 1), pattern = '[2-9]') & grepl(x = substr(res, 4, 4), pattern = '[2-9]') ) {
    return(res)}
  
  else NULL
}