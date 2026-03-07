(define/contract (rob nums)
  (-> (listof exact-integer?) exact-integer?)
  (let ([ns (length nums)])
    (cond
      [(< ns 2) (list-ref nums 0)]
      [else
       (let loop ([p 2]
                  [p2 (list-ref nums 0)]
                  [p1 (max (list-ref nums 0) (list-ref nums 1))])
         (if (= p ns)
             p1
             (let ([cv (max p1 (+ (list-ref nums p) p2))])
               (loop (add1 p) p1 cv))))]))
  )
