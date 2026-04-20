sinIntegral :: Double -> Double -> Double
sinIntegral l r =
  let
    ps = [-0.9061798459, -0.5384693101, 0, 0.5384693101, 0.9061798459]
    ws = [0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851]
  in
    ((r-l) / 2) * (sum ( zipWith (\w t -> w * sin (((r-l) * t + l + r) / 2)) ws ps))

gaussIntegral :: Int -> (Double -> Double) -> Double -> Double -> Double
gaussIntegral n f a b =
  let
    -- 把 [-1,1] 的点 t 映射到 [a,b]
    mapT t = ((b - a) * t + a + b) / 2
    -- 积分缩放系数
    scale = (b - a) / 2

    -- n点高斯积分：节点 + 权重
    (nodes, weights) = case n of
      -- 2点
      2 -> ( [-1/sqrt 3, 1/sqrt 3],
             [1, 1] )
      -- 3点
      3 -> ( [-sqrt 0.6, 0, sqrt 0.6],
             [5/9, 8/9, 5/9] )
      -- 4点
      4 -> ( [-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116],
             [0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451] )
      -- 5点（最常用）
      5 -> ( [-0.9061798459, -0.5384693101, 0, 0.5384693101, 0.9061798459],
             [0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851] )

      _ -> error "only support 2 - 5 potin gauss integral"

    sumTerms = sum $ zipWith (\w t -> w * f (mapT t)) weights nodes
  in
    scale * sumTerms

main :: IO ()
main = do
  print $ sinIntegral 0 pi
  print $ gaussIntegral 2 sin 0 pi
  print $ gaussIntegral 3 sin 0 pi
  print $ gaussIntegral 4 sin 0 pi
  print $ gaussIntegral 5 sin 0 pi
