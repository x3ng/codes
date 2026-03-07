(define/contract (climb-stairs n)
  (-> exact-integer? exact-integer?)
  (if (<= n 1)
      n
      (let loop ([rt n]
                 [s2 0]
                 [s1 1])
        (if (> rt 0)
            (loop (sub1 rt) s1 (+ s1 s2))
            s1)))
  )
