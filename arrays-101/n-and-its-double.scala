object Solution {
    def checkIfExist(arr: Array[Int]): Boolean = {
        var elems = scala.collection.mutable.Set[Int]()
        for (i <- 0 until arr.length)
        {
            if (elems.contains(arr(i) * 2)
                || (elems.contains(arr(i) / 2) && arr(i) % 2 == 0))
            {
                return true
            }
            elems.add(arr(i))
        }
        false
    }
}
