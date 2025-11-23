#pragma once
#include <iostream>
#include "types.h"



struct Trade
{
    public:
        explicit Trade(MakerId maker,
                       TakerId taker,
                       Price price,
                       Qty qty,
                       TimeNs ts) noexcept
                    : maker_id_ {maker}, taker_id_ {taker}, price_ {price}, qty_ {qty}, ts_ {ts} {};
        Trade() = delete;

        MakerId maker_id() const noexcept {return maker_id_; }
        TakerId taker_id() const noexcept {return taker_id_; }
        Price price() const noexcept {return price_; }
        Qty qty() const noexcept {return qty_; }
        TimeNs timestamp() const noexcept {return ts_; }

        
    private:
        MakerId maker_id_;
        TakerId taker_id_;
        Price price_;
        Qty qty_;
        TimeNs ts_;
    
};
