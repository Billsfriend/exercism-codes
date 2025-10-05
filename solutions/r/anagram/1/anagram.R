anagram <- function(subject, candidates) {
  require(stringr)
  require(purrr)
  lower_subject <- subject |> str_to_lower()
  lower_candidates <- candidates |> map(str_to_lower)
  sort_in_place <- function(x) {
  x |> str_split_1('') |> str_sort() |> str_flatten()
}
  anagram_index <- map(lower_candidates, sort_in_place) == sort_in_place(lower_subject) &
             lower_candidates != lower_subject
  if (!any(anagram_index)) return(c())
  candidates[anagram_index]

}
