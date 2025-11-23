#pragma once
#include <cstdint>
#include "types.h"



struct Order
{
    public:
        enum class Side : uint8_t
        {
            Buy, Sell
        };

        explicit Order(OrderId order, Side side, Price price, Qty qty, TimeNs ts)
                    : order_id_ {order}, side_ {side}, price_ {price}, qty_ {qty}, ts_ {ts} {};
        Order() = delete;
        OrderId order_id() const noexcept { return order_id_;}
        Side side() const noexcept { return side_;}
        Price price() const noexcept { return price_;}
        Qty qty() const noexcept { return qty_;}
        TimeNs timestamp() const noexcept { return ts_;}

        void reduce_qty(Qty dq) noexcept { qty_ -= dq;}
        bool filled() const noexcept { return qty_ == 0;}


    private:
        OrderId order_id_;
        Side side_;
        Price price_;
        Qty qty_;
        TimeNs ts_;

};
