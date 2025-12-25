raindrops <- function(number) {
  a1 = number %% 3
  a2 = number %% 5
  a3 = number %% 7
  result = ''
  if ( a1 * a2 * a3 != 0) {
    paste0(number)
    } else {
  if (a1 == 0) {result = paste0(result, 'Pling')}
  if (a2 == 0) {result = paste0(result, 'Plang')}
  if (a3 == 0) {result = paste0(result, 'Plong')}
   result }
}
