# clone-lin-uniswap-v3-next-sqrt

Experimental i64-scale LIN clone of [Uniswap/v3-core](https://github.com/Uniswap/v3-core) `v1.0.0` SqrtPriceMath **next-sqrt** math:
`getNextSqrtPriceFromAmount0RoundingUp`, `getNextSqrtPriceFromAmount1RoundingDown`, `getNextSqrtPriceFromInput`.

- **LIN clone:** [`src/lin_uniswap_v3_next_sqrt.lin`](src/lin_uniswap_v3_next_sqrt.lin)
- **C11 oracle:** [`test/oracles/uniswap_v3_next_sqrt_c11.c`](test/oracles/uniswap_v3_next_sqrt_c11.c)
- **Proofs (results only) live in lin-open:** https://github.com/kbelludoo/lin-open
- **Event receipt:** `docs/events/EVENT_UNISWAP_V3_NEXT_SQRT_CLONE_LIN.rulel` in lin-open

This repository is the standalone LIN copy. It is **not** Uniswap V3, **not** a Pool / SwapRouter / NFT position manager, and does **not** claim Solidity uint256 / mainnet / Q64.96 parity (`Q96=2^96` exceeds signed i64 and is rejected). It is **not** the amount-delta kernel ([clone-lin-uniswap-v3-sqrt](https://github.com/kbelludoo/clone-lin-uniswap-v3-sqrt)).

Upstream was BUSL-1.1 with Change Date 1 April 2023; the Change License is GPL-2.0-or-later (this run is 2026-10-12). This LIN kernel is an original uint64-scale implementation of the published next-sqrt formulas at Q32=2^32, not a verbatim Solidity dump.

Pinned upstream: commit `e3589b192d0be27e100cd0daaf6c97204fdb1899` (tag `v1.0.0`), `contracts/libraries/SqrtPriceMath.sol` sha256 `ddd62e3a94346248677f30f1ab009ef015e71e4b8696dcca890eeabc9dc6c149` blob `685f485da43402235c3a9ce7fd85a49597b6373a`.

Canonical goldens (uint64-scale, 128-bit product, Q32=2^32, L=1000000 unless noted):

- `next0_up(Q, 1e6, 5e5, add)` ceil = **2863311531**; floor = **2863311530** (1-unit solvency)
- `naive_next0(Q, 1e6, 5e5)` = **1** (named rejected path: wrapping `(L*sqrtP)/(L+amount*sqrtP)` misses Q-shift)
- `next1_down(Q, 1e6, L, add)` = **8589934592** = 2Q (price 1→4)
- `next_from_input(..., zeroForOne=0)` with 5e5 token1 = **6442450944** = 1.5Q
- `next0_up(Q, 1e6, 1e6, add)` = **2147483648** = Q/2 (price 1→0.25)
- `amount=2^33` naive leaves price at **Q**; real overflow fallback = **499942**
- `sqrtP=0` / `L=0` fail-close to **0**; `amount=0` returns `sqrtP`
- `1e18 * 1e18 / 1` fail-closes to **0**
