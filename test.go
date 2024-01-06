func tinhtoan(stocksProfit []int32, target int64) int {
	tmp := map[int32]int64{}
	count := 0

	for index, value := range stocksProfit {
		val, flag := tmp[int32(target)-value]
		if flag == true && int64(val) > 0 {
			count++

			// chon cap nay roi thi minh xoa no di
			tmp[int32(target)-value] -= 1
			tmp[value] -= 1
		}

		// them gia tri vua chon vao
		tmp[value] += 1

	}
	return count
}

func stockPairs(stocksProfit []int32, target int64) int32 {
	return int32(tinhtoan(stocksProfit, target))

}